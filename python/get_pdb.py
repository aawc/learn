"""
A simple module to run PDB. Similar to running python REPL but with tab
completion because of my .pdbrc
"""

import pdb

def set_break():
    """
    This one's for you, pylint!
    """
    pdb.set_trace()

if '__main__' == __name__:
    set_break()
