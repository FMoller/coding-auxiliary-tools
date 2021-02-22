"""Line Counter

Read a script and extract useful info  
"""

__author__ = "Frederico Moeller"
__copyright__ = "Copyright 2021, Frederico Moeller"
__credits__ = ["Frederico Moeller"]
__license__ = "MIT"
__version__ = "0.1"
__maintainer__ = "Frederico Moeller"
__email__ = "fredericomollerped@gmail.com"
__status__ = "Prototype"


file_name = "python_test.py"
file_path = ""


def get_ext(f_name):
    for i in range(len(f_name)-1,-1,-1):
        if f_name[i]=='.':
            return f_name[i:]
    return None
    
