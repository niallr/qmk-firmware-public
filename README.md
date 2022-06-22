# qmk-firmware
## Steps To Compile & Flash Firmware

* Install and open QMK MSYS
* Run the command below to pull the latest QMK firmware and setup as per the tutorial:

``` qmk setup SonixQMK/qmk_firmware ```

``` cd qmk_firmware ```

> (NOTE: Below command is updated vs the tutorial, which mentions branch "sn32_openrgb_new"

``` git checkout sn32_master_openrgb ```

``` git submodule update --init --recursive ```

* Overwrite keyboards folder with the latest niallr files
* Run the command below to compile the firmware:

``` qmk compile -kb ffc/ffc61 -km niallr ```

* Press Fn+Tab to put keyboard into bootloader mode
* Open SONiX Keyboard Flasher, refresh devices and press Revert To Stock Firmware
* Select "qmk-firmware/.build/ffc_ffc61_niallr.bin"
* On successful flash, the keyboard should work with the new firmware.

## Troubleshooting

> Invalid return_code: 35584

Try deleting unused keyboards from the qmk_firmware\keyboards folder.


> Compiling: quantum/rgb_matrix/rgb_matrix.c : In function 'eeconfig_update_rgb_matrix_default':
quantum/rgb_matrix/rgb_matrix.c:91:45: error: 'RGB_MATRIX_CYCLE_LEFT_RIGHT' undeclared (first use in this function); did you mean 'RGB_MATRIX_LED_FLUSH_LIMIT'?

Add "OPENRGB_ENABLE = yes" to rules.mk.
