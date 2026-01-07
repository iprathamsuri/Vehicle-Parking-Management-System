# 🚗 Vehicle Parking Management System

A **console-based Vehicle Parking Management System** developed using **C++**, demonstrating **Object-Oriented Programming (OOP)** and **binary file handling** concepts.

---

## 📌 Features

* ➕ **Add Records:** Log vehicle parking entries (Bike / Car).
* ⏱️ **Auto-Duration:** Automatic calculation of parking stay.
* 💰 **Fee Calculation:** Dynamic pricing based on vehicle type.
* 🧾 **Bill Generation:** Professional parking bill display.
* ✏️ **Update Records:** Modify vehicle exit times.
* 🗑️ **Record Management:** Delete records with ease.
* 💾 **Persistent Storage:** Data is stored securely in binary files.
* 📊 **Clean UI:** Tabular display of all records using `iomanip`.

---

## 🛠️ Technologies Used

* **Language:** C++
* **Concepts:** * Object-Oriented Programming (OOP)  
    * File Handling (Binary Files: `fstream`)  
    * Encapsulation & Data Abstraction  
    * Menu-driven Programming
* **Compiler:** GCC (MinGW / MSYS2)
* **IDE:** Visual Studio Code

---

## 📂 Project Structure

```text
Vehicle-Parking-Management-System/
│
├── VEHICLE.cpp      # Main source code
├── vehicle.dat      # Binary data file (auto-generated)
├── temp.dat         # Temporary file (used during deletion)
└── README.md        # Project documentation

▶️ How to Run the Project1️⃣ Compile the ProgramBashg++ VEHICLE.cpp -o parking
2️⃣ Run the ProgramWindows:Bashparking.exe
Linux / macOS:Bash./parking
📊 Parking Fee LogicVehicle TypeRate per HourBike₹10Car₹20Note: Parking duration is rounded up to the nearest hour.Formula: Total Fee = Hours × Rate🧾 Sample Bill OutputPlaintext========== PARKING BILL ==========
Vehicle Type : Car
Reg No       : MH12AB1234
Mobile       : 9876543210
Duration     : 3 Hours
Total Fee    : ₹60
==================================
🎓 Learning OutcomesFile I/O: Practical understanding of C++ binary file handling.OOP Principles: Implementation of real-world problems using classes and objects.Encapsulation: Protecting data using private members and getter/setter methods.Data Integrity: Safe record update and deletion using temporary files.📌 Future Enhancements💳 Payment Integration: Digital receipt storage.📄 Export Feature: Export records to CSV/Excel format.🖥️ GUI: Develop a visual interface using Qt Framework.⏰ Timestamps: Integration of real-time ctime library for entry/exit.👨‍💻 AuthorPratham Suri Full Stack Developer | AI Intern @ Infosys Springboard | Open Source Contributor (GSSoC)⭐ If you like this project, give it a star on GitHub — it motivates me to build more!
