import re # regular expression module

kick_lower_case = "kick"
kick_capital_case = "KICK"
kick_mixed_case = "KiCk"
kick_error = "KiCka"


# the flag re.I tells fullmatch function to ignore the case of the strings
print("\nWhen comparing", kick_lower_case, "with", kick_capital_case,
    "the fullmatch function called with the ignore case flag returns:",
    re.fullmatch(kick_lower_case, kick_capital_case, re.I))

print("\nWhen comparing", kick_lower_case, "with", kick_capital_case,
    "the fullmatch function called with the ignore case flag returns:",
    re.fullmatch(kick_lower_case, kick_mixed_case, re.I))

print("\nWhen comparing", kick_lower_case, "with", kick_error,
    "the fullmatch function called with the ignore case flag returns:",
    re.fullmatch(kick_lower_case, kick_error, re.I))

print("\nWhen comparing", kick_lower_case, "with", kick_capital_case,
    "the fullmatch function called without the ignore case flag returns:",
    re.fullmatch(kick_lower_case, kick_capital_case))

print("\nWhen comparing", kick_lower_case, "with", kick_mixed_case,
    "the fullmatch function called without the ignore case flag returns:",
    re.fullmatch(kick_lower_case, kick_mixed_case))



# the return value of the fullmatch function can directly be used in an if check
if re.fullmatch(kick_lower_case, kick_mixed_case, re.I):
    print("\nThe fullmatch function can directly be used as condition for an if" +
        " statement")

if re.fullmatch(kick_lower_case, kick_mixed_case):
    print("THIS LINE OF CODE IS NOT RUN")
