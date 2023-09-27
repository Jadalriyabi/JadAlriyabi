import json

# Create a dictionary to store user credentials (simplified for demonstration)
users = {
    "user1": "password1",
    "user2": "password2",
}

# Create a dictionary to store user tasks
user_tasks = {}

# Function to load user tasks from a JSON file
def load_tasks():
    global user_tasks
    try:
        with open("tasks.json", "r") as file:
            user_tasks = json.load(file)
    except FileNotFoundError:
        user_tasks = {}

# Function to save user tasks to a JSON file
def save_tasks():
    with open("tasks.json", "w") as file:
        json.dump(user_tasks, file)

# Function for user authentication
def login():
    username = input("Enter your username: ")
    password = input("Enter your password: ")
    if username in users and users[username] == password:
        return username
    else:
        return None

# Function to display tasks for a user
def display_tasks(username):
    tasks = user_tasks.get(username, [])
    if tasks:
        print("Your tasks:")
        for i, task in enumerate(tasks, start=1):
            print(f"{i}. {task['title']} - {task['description']} - {'Completed' if task['completed'] else 'Pending'}")
    else:
        print("No tasks found.")

# Function to add a new task for a user
def add_task(username):
    title = input("Enter task title: ")
    description = input("Enter task description: ")
    user_tasks.setdefault(username, []).append({"title": title, "description": description, "completed": False})
    save_tasks()
    print("Task added successfully.")

# Function to mark a task as completed
def mark_completed(username):
    display_tasks(username)
    try:
        task_index = int(input("Enter the task number to mark as completed: ")) - 1
        if 0 <= task_index < len(user_tasks[username]):
            user_tasks[username][task_index]["completed"] = True
            save_tasks()
            print("Task marked as completed.")
        else:
            print("Invalid task number.")
    except ValueError:
        print("Invalid input. Enter a valid task number.")

# Main program
load_tasks()
current_user = None

while True:
    if current_user is None:
        print("Welcome to the To-Do List App")
        print("1. Login")
        print("2. Quit")
        
        choice = input("Enter your choice: ")
        if choice == "1":
            current_user = login()
            if current_user is None:
                print("Invalid username or password")
        elif choice == "2":
            break
        else:
            print("Invalid choice")
    else:
        print(f"Welcome, {current_user}!")
        print("1. Display Tasks")
        print("2. Add Task")
        print("3. Mark Task as Completed")
        print("4. Logout")
        
        choice = input("Enter your choice: ")
        if choice == "1":
            display_tasks(current_user)
        elif choice == "2":
            add_task(current_user)
        elif choice == "3":
            mark_completed(current_user)
        elif choice == "4":
            current_user = None
        else:
            print("Invalid choice")

print("Goodbye!")
