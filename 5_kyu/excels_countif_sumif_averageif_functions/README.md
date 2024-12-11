# Excels COUNTIF SUMIF AVERAGEIF functions difficulty 5 kyu kata SOLVED

* [Description](README.md#description-of-issue)
    * [Specifications](README.md#specifications-each-function-will-take-the-same-two-arguments)
    * [Examples](README.md#examples)
* [Solution](README.md#solution)

## Description of issue
The Brief Microsoft Excel provides a number of useful functions for counting, summing, and averaging values if they meet a certain criteria. Your task is to write three functions that work similarly to Excel's **COUNTIF**, **SUMIF** and **AVERAGEIF** functions.

### Specifications Each function will take the same two arguments:

* A list object containing values to be counted, summed, or averaged.
* A criteria in either an integer, float, or string
    * Integer or float indicates equality
    * Strings can indicate >, >=, <, <= or <> (use the Excel-style "Not equal to" operator) to a number (ex. ">=3"). In the count_if function, a string without an operater indicates equality to this string.

The tests will all include properly formatted inputs. The test cases all avoid rounding issues associated with floats.

## Examples
```python
count_if([1,3,5,7,9], 3)
>>> 1

count_if(["John","Steve","John"], "John")
>>> 2

sum_if([2,4,6,-1,3,1.5],">0")
>>> 16.5

average_if([99,95.5,0,83],"<>0")
>>> 92.5
```
## Excel Function Documentation:

[COUNTIF](https://support.office.com/en-us/article/COUNTIF-function-e0de10c6-f885-4e71-abb4-1f464816df34)

[SUMIF](https://support.office.com/en-us/article/SUMIF-function-169b8c99-c05c-4483-a712-1697a653039b)

[AVERAGEIF](https://support.office.com/en-us/article/AVERAGEIF-function-faec8e2e-0dec-4308-af69-f5576d8ac642)

# [Solution](main.py)
## Import Statements:
* `from typing import TypeVar, Iterable, Callable, AnyStr`: This imports type hints from the `typing` module.
    * `TypeVar` is used to define a generic type.
    * `Iterable` is used to represent a collection of items.
    * `Callable` represents a function type.
    * `AnyStr` is a type variable representing either `str` or `bytes`.
## Type Variable:
* `Condition = TypeVar('Condition', int, float, str)`: This defines a type variable `Condition` that can be of type `int`, `float`, or `str`. This will be used to specify the type of conditions that the functions can handle.
## Function `parse_condition`:
* `parse_condition(cond: Condition) -> Callable[[int, float, AnyStr], bool]`: This function takes a `cond` parameter of type Condition and returns a function that can be applied to an `int`, `float`, or `AnyStr` (string or bytes). The returned function will return `True` or `False` based on whether the input matches the condition.
    * If `cond` is an `int` or `float`, it returns a function that checks equality (`var == cond`).
    * If `cond` is a `str`, the function checks whether it contains comparison operators (`=`, `>`, `<`).
        * If operators are found, the condition is parsed and a corresponding comparison function is returned (`>=`, `>`, `<`, `<=`, or `!=`).
        * If no operators are found, it returns a function that checks for string equality.
## Utility Functions:
These functions perform specific operations (counting, summing, and averaging) on an iterable based on a given condition.

* `count_if(values: Iterable, criteria: Condition)`:

    * This function counts the number of elements in `values` that satisfy the condition specified by `criteria`.
    * It does this by filtering the values using the `parse_condition` function and then counting the number of filtered elements using `len()`.
* `sum_if(values: Iterable, criteria: Condition)`:

    * This function calculates the sum of all elements in `values` that satisfy the condition specified by `criteria`.
    * It filters the values using `parse_condition` and then sums them using `sum()`.
* `average_if(values: Iterable, criteria: Condition)`:

    * This function calculates the average of all elements in `values` that satisfy the condition specified by `criteria`.
    * It first filters the values, then calculates the sum and divides by the count of filtered values.
