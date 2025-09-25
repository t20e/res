# Unit Testing

Prerequisites:

```shell
# Inside a python environment install:
pip install pytest pytest-mock
```


### Examples

**To test one file:**

1. Create a file (main.py) and add its code
2. Create a corresponding test file (test_main.py) to test that code.
3. Test with command:

    ```shell
        pytest test_main.py
    ```

---

**For many scripts we can automated this**. Make sure every module you want to test has a corresponding test_(moduleName).py file.

- Run this command from project root:

    ```shell
    pytest
    ```

- It will automatically find all files named `test_*.py` or `_test.py` in the current directory and all of its subdirectories.

---

### Why Unit Testing

Unit testing is a software development process in which the smallest testable parts of an application, called **units**, are individually and independently tested for proper operation. The primary goal is to **isolate** each part of the program and show individual components working correctly.
