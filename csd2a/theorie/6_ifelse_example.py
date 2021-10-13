"""
Example of if else structure and how to validate input string

If the condition of the first if statement is true,
python will skip the following else if statements.

------ EXERCISES ------
- See for yourself this indeed is the case. Change the 'snare' string in the
    first elif statement to 'kick'.
    Now run the program and enter 'kick'.
    The string "you selected the snare" is not printed to the console!
- now replace the elif at line 19 with an if.
    Run the program again and enter 'kick'.
    The string "you selected the snare" now should be printed to the console.
    Concluding: by using an elif structure, you can force python to skip the
    next condition checks and continue with the rest of the script.
"""

element = input("select a drumkit element, either type 'kick', 'snare', 'base'")
if element == 'kick':
    print("you selected the kick")

elif element == 'snare':
    print("you selected the snare")

elif element == 'base':
    print("you selected the base")
