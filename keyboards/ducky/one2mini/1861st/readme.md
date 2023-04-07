# One 2 Mini (DKON1861ST)

![one2mini](https://www.duckychannel.com.tw/upload/2019_05_112/20190511120502dgnhbl7NU1.png)

A 60% keyboard made by Ducky Channel.

* Keyboard Maintainer: [Reza Jelveh](https://github.com/fishman)
* Hardware Supported: Ducky One 2 Mini RGB / NUC123SD4AN0 / MBI5042
* Hardware Availability: [Ducky Channel](https://www.duckychannel.com.tw/en/Ducky-One2-Mini-RGB)
    * RGB LEDs are currently disabled until the driver is merged.

## Compiling the Firmware

    make ducky/one2mini:default

## Accessing Bootloader Mode

To enter the 1861ST bootloader to flash, boot the keyboard while holding D+L.

## Flashing the Firmware:

There are then two ways to flash the keyboard:

    pip install --user nuvoton-isp
    nuvoisp -f ducky_one2sf_ansi.bin

Alternatively you can use elfmimi's [nu-isp-cli](https://lib.rs/crates/nu-isp-cli) which is more complete than nuvoisp and allows flashing .hex files as well.

    cargo install nu-isp-cli
    nu-isp-cli flash ducky_one2sf_ansi.bin

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
