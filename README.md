# 🚗 Car Showroom Management System

This is a simple console-based Car Showroom Management System written in C++. It allows users to manage a list of cars in a showroom, including adding, viewing, and removing cars. All data is stored in a local file (`cars.collection`) for persistence.

---

## 📋 Features

- View all available cars in the showroom
- Add a new car with name, model, and size
- Remove an existing car by name
- File-based storage to retain data between sessions
- Text-based UI with simple menu options

---

1. **Car Addition**  
   When a car is added, it is stored in memory **and** written to `cars.collection`.

2. **Viewing Cars**  
   The `show()` function reads and displays all entries from `cars.collection`.

3. **Removing a Car**  
   A car is removed from memory (current session only) based on the name provided by the user.

> ⚠️ Note: Removing a car does **not** update the `cars.collection` file. File updating would require rewriting the entire file manually.

---

## 🧪 Sample Cars on Startup

When the program starts, three cars are added by default:

- Ferrari (2014) — Size: 4  
- Mehran (2023) — Size: 5  
- Alto (2013) — Size: 9  

---

