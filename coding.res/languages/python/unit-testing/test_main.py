from main import get_weather, add, divide, UserManager, Database, is_prime
import pytest



def test_get_weather():
    assert get_weather(21) == "hot"
    assert get_weather(19) == "Cold"


def test_add():
    assert add(2, 3) == 5, "2+3 should be 5"
    assert add(-1, 1) == 0, "-1 + 1 should be 0"
    assert add(0, 0) == 0, "0 + 0 should be 0"


def test_divide():
    # Catch the raised error string match
    with pytest.raises(ValueError, match="Cannot divide by zero"):
        divide(10, 0)


@pytest.fixture
def user_manager():
    """
    Creates a fresh instance of UserManager before each test
        - Always isolate the component in this example we isolate duplicate user and add user i.e instantiating the UserManager once for each test below
    """
    return UserManager()


################################################
# CLASS TESTING
################################################
def test_add_user(
    user_manager,
):  # the user_manager arg is the name of the fixture above
    assert user_manager.add_user("john_doe", "john@gmail.com") == True
    assert user_manager.get_user("john_doe") == "john@gmail.com"


def test_add_duplicate_user(
    user_manager,
):  # the user_manager arg is the name of the fixture above
    assert user_manager.add_user("john_doe", "john@gmail.com")
    with pytest.raises(ValueError):
        user_manager.add_user("john_doe", "anotherEmail@gmail.com")


################################################
# DATABASE TESTING
################################################
@pytest.fixture
def db():
    """
    Provides a fresh instance of the Database class and cleans up after the test.
    """
    database = Database()

    # === Anything before yield runs before the test
    yield database  # Provide the fixture instance whenever it needs to be used

    # === Anything after yield runs after the test/ clean-up
    database.data.clear()  # Cleanup step (not needed for in-memory, but useful for real DBs)


def test_add_user(db):
    db.add_user(1, "Alice")
    assert db.get_user(1) == "Alice"


def test_add_duplicate_user(db):
    db.add_user(1, "Alice")
    with pytest.raises(ValueError, match="User already exists"):
        db.add_user(1, "Bob")


def test_delete_user(db):
    db.add_user(1, "Bob")
    db.delete_user(2)
    assert db.get_user(2) is None


################################################
# Parameterized Testing
# A way not to write a tone of duplicated code like many asserts
################################################


@pytest.mark.parametrize(
    "num, expected",
    [
        (1, False), # (num, expected)
        (2, True), # (num, expected)
        (3, True),
        (4, False),
        (17, True),
        (18, False),
        (19, True),
        (25, False),
    ],
)
def test_is_prime(num, expected):
    assert is_prime(num) == expected
    # Instead of making many repetitive asserts



################################################
# MOCKING
# example the frontend api needs something from the backend api, so we "mock" create a fake backend so that we can test the frontend, so mocking is for testing components that rely on other components.
################################################