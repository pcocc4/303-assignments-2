# Stack and Linked List Program

This C++ program provides two interactive menus for working with core data structures:
- **Stack** (using `std::vector`)
- **Singly Linked List**

Users can:
- Add, remove, and view elements
- Search and modify data
- Calculate the average of stack values
- Check if structures are empty
- Exit the program

---

## Requirements
- **Windows 10/11**
- **Visual Studio** (Community Edition or higher) with "Desktop development with C++" workload installed

---

## Files
- `main.cpp` — Main program file containing the menu logic and entry point  
- `Stack.cpp` / `Stack.h` — Stack class implementation and header  
- `LinkedList.cpp` / `LinkedList.h` — Linked List class implementation and header  
- Additional helper functions and input validation routines (if applicable)

---

## How to Compile and Run (Windows, Visual Studio)

### 1. Open the Project
- Launch Visual Studio  
- Open the `.sln` file for this project (or create a new one and add all `.cpp` and `.h` files)

### 2. Build the Program
- In Visual Studio, go to **Build → Build Solution** (or press `Ctrl + Shift + B`)  
- Check the Output window for any compilation errors

### 3. Run the Program
- Press `Ctrl + F5` (Start Without Debugging) or click the green **Run** button  
- The menu will appear in the console

---

## Follow the Menu Prompts

### 🔗 Linked List Menu
1. **Add Element at End** — Appends a value to the end of the list  
2. **Insert at Index** — Inserts a value at a specific position  
3. **Remove by Index** — Deletes the node at a given index  
4. **Search for Value** — Finds the index of a specific value  
5. **Display List** — Prints all elements in the list  
6. **Check if Empty** — Reports whether the list is empty  
7. **Exit** — Returns to main menu or exits program  

### 📚 Stack Menu
1. **Push Element** — Adds a value to the top of the stack  
2. **Pop Top Element** — Removes the top value  
3. **View Top** — Displays the top value without removing it  
4. **Display Stack** — Prints all stack elements  
5. **Check if Empty** — Reports whether the stack is empty  
6. **Calculate Average** — Computes the average of all stack values  
0. **Exit** — Returns to main menu or exits program  

---

## Notes
- Both structures are dynamically managed to ensure safe memory usage and flexibility  
- Input validation prevents crashes from invalid or unexpected user input  
- The stack uses `std::vector` for automatic resizing and efficient access  
- The linked list is singly linked and supports indexed operations  
