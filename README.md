# 🚗 Vehicle Parking Management System

A **console-based Vehicle Parking Management System** developed using **C++**, demonstrating **Object-Oriented Programming (OOP)** and **binary file handling** concepts.

---

## 📌 Features

- ➕ Add vehicle parking records (Bike / Car)
- ⏱️ Automatic parking duration calculation
- 💰 Parking fee calculation based on vehicle type
- 🧾 Parking bill generation
- ✏️ Update vehicle exit time
- 🗑️ Delete vehicle records
- 💾 Persistent storage using binary files
- 📊 Clean tabular display of records

---

## 🛠️ Technologies Used

- **Language:** C++
- **Concepts:**  
  - Object-Oriented Programming (OOP)  
  - File Handling (Binary Files)  
  - Encapsulation & Data Abstraction  
  - Menu-driven Programming
- **Compiler:** GCC (MinGW / MSYS2)
- **IDE:** Visual Studio Code

---

## 📂 Project Structure

Vehicle-Parking-Management-System/
│
├── VEHICLE.cpp # Main source code
├── vehicle.dat # Binary data file (auto-generated)
├── temp.dat # Temporary file (used during deletion)
└── README.md
---

## ▶️ How to Run the Project

### 1️⃣ Compile the Program
g++ VEHICLE.cpp -o parking
2️⃣ Run the Program
Windows:
bash
Copy code
parking.exe

Linux / macOS:
bash
Copy code
./parking

📊 Parking Fee Logic
Vehicle Type	Rate per Hour
Bike	₹10
Car	₹20
Parking duration is rounded up to the nearest hour
Fee = Hours × Rate

🧾 Sample Bill Output
========== PARKING BILL ==========
Vehicle Type : Car
Reg No       : MH12AB1234
Mobile       : 9876543210
Duration     : 3 Hours
Total Fee    : ₹60
=================================
🎓 Learning Outcomes
Practical understanding of C++ file handling
Implementation of real-world problem using OOP
Use of getter methods for encapsulation
Safe record update and deletion using temporary files
Clean console formatting with iomanip

📌 Future Enhancements
💳 Payment receipt storage
📄 Export records to CSV
🖥️ GUI version using Qt
🌐 Web-based version (MERN stack)
⏰ Real-time entry/exit timestamps

👨‍💻 Author
Pratham Suri

Full Stack Developer

AI Intern @ Infosys Springboard

Open Source Contributor (GSSoC)

⭐ If you like this project
Give it a ⭐ on GitHub — it motivates me to build more!

