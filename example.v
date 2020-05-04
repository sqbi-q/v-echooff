import echo
import os

fn main(){
	nick := os.input("Nickname: ")

	//MAKE INPUT INVISIBLE
	echo.display_input(false)
	pass := os.input("Password: ")

	//make input visible again
	echo.display_input(true)
}