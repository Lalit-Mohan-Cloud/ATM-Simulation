# ATM Simulator (C++)

A console-based ATM simulation program that supports:
- Balance inquiry
- Deposit and withdrawal
- PIN-based access control
- File-based balance persistence

## Features
✅ English-only UI  
✅ PIN check before transactions  
✅ Input validation (e.g., deposits/withdrawals must be multiples of 100)  
✅ Data stored in `info.txt`  

## How to Run
1. Make sure `info.txt` exists with a numeric balance (e.g., `5000`)
2. Compile: `g++ atm.cpp -o atm.exe`
3. Run: `atm.exe`

## Future Improvements
- Hindi UI support
- PIN encryption
- GUI version (with Qt or C++/CLI)

