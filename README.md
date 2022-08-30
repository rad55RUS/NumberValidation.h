# NumberValidation.h
My library for entering numbers, their validation and entering sequence (sequences may be separated later)
<br> <br>

## Number entering functions
### Integer entering
`enterInteger()`&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;   - enter integer <br>
`enterInteger(int min)`&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;  - enter integer greater than ***min*** <br>
`enterInteger(int min, int max)`&nbsp;&nbsp;&nbsp;                       - enter integer greater than ***min*** and less than ***max*** <br>
### Double entering
`enterDouble()`&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;   - enter double <br>
`enterDouble(int min)`&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  - enter double greater than ***min*** <br>
`enterDouble(int min, int max)`&nbsp;&nbsp;&nbsp;&nbsp;                       - enter double greater than ***min*** and less than ***max*** <br>
## Sequnce entering
### Sequence entering to vector
`enterSequence(vector<int> seq)`&nbsp;&nbsp;&nbsp;          - enter sequence ***seq*** <br>
## Validation functions (used by number entering functions)
`isInteger(string number)`&emsp;&emsp;&emsp;&nbsp;&nbsp;     - check string ***number*** for integer <br>
`isDouble(string number)`&emsp;&emsp;&emsp;&emsp;            - check string ***number*** for double <br>
