# ATM Workflow Project

This folder contains a procedural C++ ATM simulation using multiple files and namespaces.

## Structure
- `main.cpp` - application entry point
- `atm.h` / `atm.cpp` - program orchestration
- `auth.h` / `auth.cpp` - login and authentication logic
- `menu.h` / `menu.cpp` - menu flows for admin and common users
- `accounts.h` / `accounts.cpp` - account management routines
- `utils.h` / `utils.cpp` - input helpers and shared utilities
- `user_data.h` / `user_data.cpp` - file-based user persistence

## User types
- `admin`
- `common`

## Build
From the `atm` folder:
```bash
g++ main.cpp atm.cpp auth.cpp menu.cpp accounts.cpp utils.cpp user_data.cpp -o atm_app
```

## Run
```bash
./atm_app
```

## Notes
- Uses `atm_users.txt` in the same folder to store users.
- If the file does not exist, it is created with sample admin/common accounts.
