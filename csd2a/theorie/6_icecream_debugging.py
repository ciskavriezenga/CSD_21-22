from icecream import ic # = module for debugging


selected_instrument = "kick"

# instead of using the print as follow
print("selected_instrument:", selected_instrument)

# we can use the icecream module
ic(selected_instrument)

# and disable debugging :D
ic.disable()

# now the following will print nothing
ic(selected_instrument)

# after enabling ic will print again
ic.enable()
ic("ic is enabled again")
ic(selected_instrument)

# another nice thing, if you just quickly want to see if a line is reached
# e.g. in an if else check , simply add ic()
if 'foo' == 'bar':
    ic()
else:
    ic() # ic prints '28' (=line number) to the console!
