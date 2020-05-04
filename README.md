# V Echo Off

Turn on/off input printing for V. Written in C/V.

## Installation

Clone using Git or download ZIP.

```bash
git clone https://github.com/sqbi-q/v-echooff
```

## Usage

Paste echo folder to your's project, and then import module echo.

**Project tree:**
```
|-- echo
|   |-- echo.c
|   |-- echo.h
|   |-- echo.o
|   |-- echo.v
|   -- v.mod
-- example.v
```


**example.v:**
```v
//our module
import echo

//for input
import os

fn main(){
	nick := os.input("Nickname: ")

	//MAKE INPUT INVISIBLE
	echo.display_input(false)
	pass := os.input("Password: ")

	//make input visible again
	echo.display_input(true)
}
```
