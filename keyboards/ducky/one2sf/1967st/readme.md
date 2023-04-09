# One 2 SF (DKON1967ST)

![One 2 SF](https://www.duckychannel.com.tw/upload/2019_05_142/201905141721227o2fxn6LX1.png)

A 65% keyboard made by Ducky Channel.

This firmware was tested on the Ducky One 2 SF 1967ST version.

* Keyboard Maintainer: [f7urry](https://github.com/f7urry)
* Hardware Supported: Ducky One 2 SF RGB (DKON1967ST) + NUC123SD4AN0 + MBI5043GP
* Hardware Availability: [Ducky Channel](https://www.duckychannel.com.tw/en/Ducky-One2-SF)
    * RGB LEDs are currently disabled until the driver is merged.

## Compiling the Firmware

```
make ducky/one2sf/1967st:default
```

## Accessing Bootloader Mode

To enter the 1967ST bootloader to flash, boot the keyboard while holding D+L.

## Flashing the Firmware

There are then two ways to flash the keyboard:

```
pip install --user nuvoton-isp
nuvoisp -f ducky_one2sf_ansi.bin
```

Alternatively you can use elfmimi's [nu-isp-cli](https://lib.rs/crates/nu-isp-cli) which is more complete than nuvoisp and allows flashing .hex files as well.

```
cargo install nu-isp-cli
nu-isp-cli flash ducky_one2sf_ansi.bin
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Original Firmware

It's often helpful to have the proprietary firmware to compare this one with when developing. However, Ducky Channel only provides the firmware in the form of a Windows-only utility, but it is possible to extract the firmware binary if you know the firmware's location inside of the utility (Credit to [/u/DarioSinoLogic16](https://reddit.com/comments/zker40/comment/j0iql61) on Reddit for the inspiration).

### Known Start/End Addresses

These are well-known firmware start/end addresses. While there's no guarantee that they'll work or won't brick your keyboard, they've all been manually tested and work.

Download | Utility Name | Utility SHA512 | Start Address | End Address | Firmware SHA512
--- | --- | --- | --- | --- | ---
[`20220919101715ca3l950D41.zip`](https://www.duckychannel.com.tw/upload/2022_09_192/20220919101715ca3l950D41.zip) | `Ducky_One2_SF_V1.14.exe` | `a349a4c62ab198a7b68efb71af7937530d046710579c05674ec5c0802df7e598e9df5f63476f8be209e26f6ee85e744d6d3ca65eb8896a3800d3e0fd869a5c2a` | `0x207db0` | `0x2126db` | `c014d3cb5c10d72e816753f7d9adc1dad58202ef35e48713b8b3bf1fa1d3490c84fd562cc3ab41595ee8cef02573555d8982ca6e02388f84fc40362179f0546e`

### Calculating the Start/End Addresses

This step is required if you don't already know start/end addresses. Note that you'll need a computer/VM with Windows installed on it.

1. Install [Ghidra](https://ghidra-sre.org) and [WireShark](https://wireshark.org) (With USBPCap)
2. Open WireShark and select the appropriate USB interface, and start capturing USB packets (You can tell if the interface is the right one by pressing keys on your keyboard and seeing if the incoming packets roughly correlate with when you pressed the keys)
3. Use the firmware update utility to update your keyboard's firmware like you would normally
4. Stop the capture
5. Apply a display filter to show only USB packets sent to your keyboard (i.e.: `usb.dst == "X.Y.Z"`; replace `X.Y.Z` with the appropriate address)
6. Choose a random packet (Generally avoid the first/last ~10 packets as well as those with lower entropy/lots of `0`'s)
7. Copy ~8 bytes from near end of the HID Data field (Again avoid anything with lower entropy/lots of `0`'s)
8. Open Ghidra, create a new project, import the firmware update utility, and actually open the firmware update utility (in Ghidra)
9. Press `s` or click `Search` in the menu bar, paste the bytes you copied from step 7, click `Advanced >>`, select `Big Endian` for the byte order, then click `Search All`
10. If Ghidra shows anything other than exactly one match, go back to step 6 and choose a different packet
11. Click on the match to go to the address
12. Press `CTRL + ALT + T` or click the vertical arrow in the menu bar to toggle the code unit search direction (Make sure the arrow points upwards)
13. Press `CTRL + ALT + L` or click the blue `L` icon to go to the previous label
14. In Wireshark, press `CTRL + F` or click on the search icon, search for the **<u>next</u>** ~8 bytes from the address you're currently at in Ghidra, and ensure it matches one of the **<u>first</u>** few packets (This ensures you're at the start of the firmware)
15. Back in Ghidra, hover over the address and record the byte source offset (Ignore the `+` and `h`; this is the start address)
16. Press `CTRL + ALT + T` or click the vertical arrow in the menu bar to toggle the code unit search direction (Make sure the arrow points downwards)
17. Press `CTRL + ALT + L` or click the blue `L` icon to go to the next label
18. In Wireshark, press `CTRL + F` or click on the search icon, search for the **<u>previous</u>** ~8 bytes from the address directly **<u>preceeding</u>** the one you're currently at in Ghidra, and ensure it matches one of the **<u>last</u>** few packets (This ensures you're at the end of the firmware)
19. Back in Ghidra, hover over the **<u>preceding</u>** address and record the byte source offset (Ignore the `+` and `h`; this is the end address)

### Extracting the Firmware

1. Extract the firmware:
```powershell
# Windows
$startAddress = 0xYYYYYY # Replace with the start address
$endAddress = 0xZZZZZZ # Replace with the end address

$raw = Get-Content -Path UTILITY_PATH -AsByteStream -Raw # Replace UTILITY_PATH with the path to the utility
$firmware = $raw[$startAddress..($endAddress - 1)]
Set-Content -Path firmware.bin -Value $firmware -AsByteStream
```
or
```bash
# Linux
startAddress=$((0xYYYYYY)) # Replace with the start address
endAddress=$((0xZZZZZZ)) # Replace with the end address

dd if=UTILITY_PATH of=firmware.bin bs=1 skip=$startAddress count=$(($endAddress - $startAddress)) # Replace UTILITY_PATH with the path to the utility
```
2. Hold `D` and `L` while plugging in the keyboard
3. Flash the firmware:
```
nu-isp-cli flash firmware.bin
```
