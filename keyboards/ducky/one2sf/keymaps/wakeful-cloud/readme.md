# Wakeful Cloud's Ducky One 2 SF Keymap

## Build

1. Run:
```bash
qmk compile -kb ducky/one2sf/1967st -km wakeful-cloud
```

## Flash

1. Hold `D` and `L` while plugging in the keyboard
2. Run:
```bash
nu-isp-cli flash .build/ducky_one2sf_1967st_wakeful-cloud.bin
```