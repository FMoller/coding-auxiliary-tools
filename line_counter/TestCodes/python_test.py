"""A simple file to test the line_counter performance in python
This is a multiline doctest
"""

__author__ = "Frederico Moeller"
__copyright__ = ""
__credits__ = ["Frederico Moeller"]
__license__ = "MIT"
__version__ = "1.0.1"
__maintainer__ = "Frederico Moeller"
__email__ = ""
__status__ = ""

#import things
import math
 

#define things
def some_function(var_one, var_two,
                  var_three):
    """This is a function that do things"""
    
    if var_one > var_two:
        if var_two*var_three > var_one:
            return "blab" #this happens
        else:
            return "blob"
    else:
        return "fish"
