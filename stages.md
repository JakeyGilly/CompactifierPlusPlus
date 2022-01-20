# All About The Compacting Stages
## Stage 1: Compact
This stage is the most basic of the compacting stages. It will remove all comments and whitespace from the file, remove comments.
This stage will not alter the code in any way.

## Stage 2: Compact
This stage will do everything that Stage 1 does, but it will also compact code. It will try and fo the following:

* Remove unused variables and functions
* Remove unused imports
* convert imports to only import required modules
* Remove code duplication
* Convert strings to use the f-string ```f"var = {variable}"```
* and more...

## Stage 3: Annoyingly Compact
This stage will do everything that Stage 2 does, but it will also do more. It will try and do the following:

* Try to convert some if-else statements to ternary operators ```var = true if x == 2 else false```
* Try to make functions one line long if possible ```def func(x): return x + 1``` instead of 
    ```
    def func(x):
        var = x + 1
        return var
    ```
* Make if, for and while statements executing only one line on the same line ```if x: print(x)```
* List and Dictionary Comprehensions ```var = [x for x in range(10)]```
* And more...
