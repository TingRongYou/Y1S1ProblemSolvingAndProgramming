# Queen Beauty Service Management System 💇‍♀️💅

A robust, console-based business management application written in C++ for the BACS1013 Problem Solving and Programming course at TARUMT. Designed as an introductory end-to-end management workflow platform, this system manages appointment operations, tracking administration, customer information, and treatment data for a modern salon environment.

## 🚀 Project Overview
Automated operational control is vital for service providers balancing real-time bookings with staff resource constraints. This software provides an interface to execute critical business functions natively within the terminal. It leverages structured procedural loops, custom data fields (`struct`), pointer validation rules, and built-in text styling to give users a highly interactive execution environment. 

To maintain efficiency without a relational database, the platform serializes structural records directly into local storage data files (`.dat`), ensuring that customer data, slot selections, and administrative settings persist fully across computational sessions.

## ✨ Key Features

* **Dual-Track Access Control Systems:**
  * **Administrative Hub:** Secure access gate matching encoded credential files (`admin.dat`, `adminDetail.dat`) enabling business managers to review records, audit treatment logs, and monitor operational workflows.
  * **Customer Portal:** Dedicated interactive view providing profile registration, appointment scheduling, and service catalog exploration.
* **Persistent Appointment & Slot Booking Engine:** Features error-checked slot allocation utilities backed by local tables (`bookedSlots.dat`) to block overlapping schedules and streamline treatment times tracking.
* **Comprehensive Resource Directories:** Maintained modules for editing and processing service files (`TBTreatment.dat`) alongside thorough subscriber archives (`customers.dat`, `customerDetail.dat`).
* **Algorithmic Data Sorting & Processing:** Utilizes custom-coded classical algorithms (such as **Bubble Sort**) to re-order customer database information dynamically for targeted reporting structures.
* **Granular Terminal Validation Layers:** Hardened input parsing modules handling invalid entry characters, out-of-bounds metrics, and blank submissions to guarantee programmatic stability.

## 🛠️ Tech Stack & Architecture

* **Core Programming Engine:** C++ (Standard ISO/IEC 14882 Framework)
* **Development Environment:** Microsoft Visual Studio (x64 Native Compiler Tools)
* **Data Persistence Framework:** Procedural Stream-to-Disk Input/Output (`fstream` Binary/Text Flat Files)

## 📁 Core Directory Structure

```text
QueenBeautyService/
├── beautyServiceAssignment.sln      # Main Microsoft Visual Studio Project Solution File
├── beautyServiceAssignment.vcxproj  # Native VC++ Project Configuration Build File
├── mainMenu.cpp                      # Consolidated C++ Codebase (UI Layer, Validation & System Logic)
├── admin.dat                         # Serialized System Authentication Records
├── adminDetail.dat                   # Secondary Administrative Profile Parameters
├── customers.dat                     # Registered Customer Authentication Database
├── customerDetail.dat                # Granular Lifestyle & Contact Demographics Table
├── bookedSlots.dat                   # Slot Booking Schedule Ledger
├── TBTreatment.dat                   # Standard Treatment Catalog Details Matrix
└── x64/Debug/
    └── beautyServiceAssignment.exe   # Compiled Operational Native Executable Binary
```

## ⚙️ Installation & Execution Guidelines
1. Requirements Setup
   To compile or modify the underlying logic structures, make sure your operating system environment includes:
   * An integrated compiler platform supporting standard C++ (Microsoft Visual Studio 2022+ recommended).
2. Building from Source
   1. Clone or extract this project folder to your workspace directory.
   2. Open `beautyServiceAssignment.sln` inside your Visual Studio software.
   3. Build the solution using `Ctrl + Shift + B` (configured to **Debug / x64** or **Release / x64** target vectors).
  
3. Execution Setup (Standalone Run)
   To run the terminal application without launching an IDE:
   1. Navigate to the execution subfolder (`x64/Debug/`).
   2. Run the executable file: `beautyServiceAssignment.exe`.
   3. **CRITICAL**: Ensure all corresponding database elements (`.dat files`) are placed alongside the executable file in that exact working folder directory, otherwise text-parsing streams may generate blank ledger instances.
  
## 👨‍💻 Authors
* **Ting Rong You**
* **Yong Chong Xin**
* **Wan Zi Kang**

_Bachelor of Software Engineering (Honours)_ 

_Tunku Abdul Rahman University of Management and Technology (TARUMT)_

_Year 1 Semester 1 — Problem Solving and Programming Assignment_
