# Music Playlist Manager

A command-line music playlist manager written in C, featuring a doubly-linked list implementation, persistent storage, and intuitive navigation controls.

**Version:** 1.0.0  
**Language:** C (C99 standard)  
**Last Updated:** April 24, 2026

---

##  Table of Contents

- [Features](#-features)
- [Data Structure](#-data-structure)
- [Prerequisites](#-prerequisites)
- [Installation](#-installation)
- [Usage](#-usage)
- [Operations](#-operations)
- [Examples](#-examples)
- [File Format](#-file-format)
- [Error Handling](#-error-handling)
- [Limitations](#-limitations)
- [Future Enhancements](#-future-enhancements)
- [Contributing](#-contributing)
- [License](#-license)
- [Contact](#-contact)

---

##  Features

- **Persistent Storage:** Automatically save and load playlists from `playlist.txt`
- **Doubly-Linked List:** Efficient bidirectional navigation through songs
- **Easy Navigation:** Play next/previous songs with instant display
- **Search Functionality:** Find songs by serial number in the playlist
- **Dynamic Memory:** Efficient memory allocation and deallocation
- **User-Friendly Interface:** Intuitive menu-driven system
- **Session Continuation:** Continue from where you left off
- **Auto-Load:** Loads saved playlist on startup

---

##  Data Structure

### Node Structure
```c
struct node {
    char title[50];      // Song title
    char artist[50];     // Artist/Singer name
    int duration;        // Duration in seconds
    struct node* prev;   // Pointer to previous song
    struct node* next;   // Pointer to next song
};
```

### Key Variables
- **`current`:** Global pointer tracking the currently playing song
- **`head`:** Pointer to the first song in the playlist
- **`playlist.txt`:** Persistent storage file

---

##  Prerequisites

- **C Compiler:** GCC 4.8+ or any C99-compatible compiler
- **Operating System:** Linux/Unix/Windows (portable C code)
- **File Permissions:** Write access for `playlist.txt` file
- **Knowledge:** Basic understanding of linked lists (helpful but not required)

---

##  Installation

### Clone or Download
```bash
# If using git
git clone https://github.com/yourusername/music-playlist-manager.git
cd music-playlist-manager

# Or download the source file directly
```

### Compile the Program
```bash
gcc -std=c99 music_playlist.c -o playlist -Wall
```

Or without warnings flag:
```bash
gcc music_playlist.c -o playlist
```

### Run the Program
```bash
./playlist
```

### For Windows Users
The code is portable and should compile on Windows without modifications:
```bash
gcc -std=c99 music_playlist.c -o playlist.exe
```

---

##  Usage

### Starting the Program

```bash
./playlist
```

### First Run

On first run:
1. Program looks for `playlist.txt`
2. If no saved playlist exists, you'll see: **"No saved playlist found."**
3. The main menu appears
4. Start adding songs to create your playlist

### Main Menu

```
===== MUSIC PLAYLIST MANAGER =====
==================================

1. Add 
2. Delete 
3. Display 
4. Current 
5. Next 
6. Prev 
7. Search 
8. Exit

Enter your choice: _
```

### Current Song Display

When a song is loaded or playing:
```
Now Playing:
----------------------------------
Title   : Song Name
Artist  : Artist Name
Duration: XXX sec
----------------------------------
```

---

##  Operations

### 1. Add Song (Option 1)
Adds a new song to the end of the playlist.

**Steps:**
1. Select option `1`
2. Enter song title (up to 49 characters)
3. Enter artist name (up to 49 characters)
4. Enter duration in seconds (integer)
5. Song is automatically appended and saved

**Example:**
```
Enter song title: Bohemian Rhapsody
Enter artist name: Queen
Enter duration (in seconds): 354
```

### 2. Delete Song (Option 2)
Removes a song from the playlist by position.

**Steps:**
1. Select option `2`
2. Enter the index/position number (1-based)
3. Song is deleted and playlist is updated

**Features:**
- Updates `current` pointer if currently playing song is deleted
- Handles edge cases (first song, last song, middle songs)
- Automatically saves changes

**Example:**
```
Enter the index of song you want to delete: 2
```

### 3. Display Playlist (Option 3)
Shows all songs in the playlist in tabular format.

**Output Format:**
```
----- PLAYLIST -----
No  Title                Artist           Duration
 1. Song One           | Artist One      |  200 sec
 2. Song Two           | Artist Two      |  180 sec
 3. Song Three         | Artist Three    |  220 sec
--------------------
```

**Features:**
- Displays serial number, title, artist, and duration
- Handles empty playlist gracefully
- Formatted for easy reading

### 4. Current Song (Option 4)
Displays the currently playing song details.

**Behavior:**
- Shows title, artist, and duration of the current song
- Returns message if no song is currently playing

**Output:**
```
Now Playing:
----------------------------------
Title   : Current Song Title
Artist  : Current Artist Name
Duration: XXX sec
----------------------------------
```

**Use Cases:**
- Check what song is currently playing
- Quick reference without navigating away

### 5. Play Next Song (Option 5)
Moves to the next song in the playlist.

**Behavior:**
- Displays next song details
- Updates `current` pointer
- Shows message if already at the end

**Output:**
```
Now Playing:
----------------------------------
Title   : Next Song Title
Artist  : Next Artist Name
Duration: XXX sec
----------------------------------
```

### 6. Play Previous Song (Option 6)
Moves to the previous song in the playlist.

**Behavior:**
- Displays previous song details
- Updates `current` pointer
- Shows message if already at the beginning

**Output:**
```
Now Playing:
----------------------------------
Title   : Previous Song Title
Artist  : Previous Artist Name
Duration: XXX sec
----------------------------------
```

### 7. Search Song (Option 7)
Finds and displays a specific song by its serial number.

**Steps:**
1. Select option `7`
2. Enter the serial number you want to search
3. Song details are displayed

**Example:**
```
Enter the serial number of the song: 3

----- PLAYLIST -----
No  Title                Artist           Duration
 3. Song Three         | Artist Three    |  220 sec
--------------------
```

### 8. Exit (Option 8)
Saves the playlist and exits the program.

**Process:**
1. Saves all songs to `playlist.txt`
2. Terminates the program

---

##  Examples

### Example 1: Creating a New Playlist

```
No saved playlist found.

===== MUSIC PLAYLIST MANAGER =====
==================================

1. Add 
2. Delete 
3. Display 
4. Current 
5. Next 
6. Prev 
7. Search 
8. Exit

Enter your choice: 1

Enter song title: Imagine
Enter artist name: John Lennon
Enter duration (in seconds): 183

===== MUSIC PLAYLIST MANAGER =====
==================================

1. Add 
2. Delete 
3. Display 
4. Current 
5. Next 
6. Prev 
7. Search 
8. Exit

Enter your choice: 1

Enter song title: Hey Jude
Enter artist name: The Beatles
Enter duration (in seconds): 427

===== MUSIC PLAYLIST MANAGER =====
==================================

1. Add 
2. Delete 
3. Display 
4. Current 
5. Next 
6. Prev 
7. Search 
8. Exit

Enter your choice: 3

----- PLAYLIST -----
No  Title                Artist           Duration
 1. Imagine            | John Lennon    |  183 sec
 2. Hey Jude           | The Beatles    |  427 sec
--------------------
```

### Example 2: Checking Current Song

```
Enter your choice: 4

Now Playing:
----------------------------------
Title   : Imagine
Artist  : John Lennon
Duration: 183 sec
----------------------------------

Enter your choice: 5

Now Playing:
----------------------------------
Title   : Hey Jude
Artist  : The Beatles
Duration: 427 sec
----------------------------------

Enter your choice: 4

Now Playing:
----------------------------------
Title   : Hey Jude
Artist  : The Beatles
Duration: 427 sec
----------------------------------
```

### Example 3: Navigation Through Playlist

```
Now Playing:
----------------------------------
Title   : Imagine
Artist  : John Lennon
Duration: 183 sec
----------------------------------

Enter your choice: 5

Now Playing:
----------------------------------
Title   : Hey Jude
Artist  : The Beatles
Duration: 427 sec
----------------------------------

Enter your choice: 6

Now Playing:
----------------------------------
Title   : Imagine
Artist  : John Lennon
Duration: 183 sec
----------------------------------
```

### Example 4: Deleting a Song

```
----- PLAYLIST -----
No  Title                Artist           Duration
 1. Imagine            | John Lennon    |  183 sec
 2. Hey Jude           | The Beatles    |  427 sec
 3. Blah Blah          | Artist Name    |  200 sec
--------------------

Enter your choice: 2

Enter the index of song you want to delete: 2

----------------------------------
Song delete successfully
----------------------------------

===== MUSIC PLAYLIST MANAGER =====

Enter your choice: 3

----- PLAYLIST -----
No  Title                Artist           Duration
 1. Imagine            | John Lennon    |  183 sec
 2. Blah Blah          | Artist Name    |  200 sec
--------------------
```

### Example 5: Searching for a Song

```
Enter your choice: 7

Enter the serial number of the song: 1

----- PLAYLIST -----
No  Title                Artist           Duration
 1. Imagine            | John Lennon    |  183 sec
--------------------
```

---

##  File Format

### Playlist File Structure

**Filename:** `playlist.txt`

**Format:** CSV (Comma-Separated Values)
```
Song Title,Artist Name,Duration
```

**Example `playlist.txt`:**
```
Imagine,John Lennon,183
Hey Jude,The Beatles,427
Bohemian Rhapsody,Queen,354
Stairway to Heaven,Led Zeppelin,482
```

### File Characteristics

| Property | Details |
|----------|---------|
| **Name** | `playlist.txt` |
| **Format** | Plain text, CSV |
| **Delimiter** | Comma (`,`) |
| **Location** | Same directory as executable |
| **Auto-Created** | On first save |
| **Auto-Loaded** | On program startup |
| **Encoding** | UTF-8 (standard) |

### Save Behavior
- Songs are saved in order of appearance
- File is overwritten on each save
- No backup is created

### Load Behavior
- File is read sequentially
- Songs are reconstructed in the same order
- Invalid lines are skipped with `continue`

---

##  Error Handling

| Error Type | Condition | User Feedback |
|-----------|-----------|---------------|
| **Empty Playlist** | Attempting to delete from empty list | "Playlist is empty." |
| **Memory Allocation Failure** | `malloc()` returns NULL | "Memory allocation failed." |
| **File Not Found** | `playlist.txt` doesn't exist on startup | "No saved playlist found." |
| **Invalid Position** | Deleting with out-of-range index | "Invalid position." |
| **End of Playlist** | Attempting next when at last song | "End of playlist." |
| **Beginning of Playlist** | Attempting previous when at first song | "No previous song." |
| **Empty Playlist on Navigation** | Current is NULL | "Playlist is empty." |
| **No Current Song** | Checking current when None playing | "No song is playing." |
| **Successful Deletion** | Song deleted successfully | "Song delete successfully" |

### Graceful Degradation

The program handles edge cases smoothly:
- **First song deletion:** Automatically updates `current` and `head`
- **Last song deletion:** Updates `prev` pointer correctly
- **Middle song deletion:** Maintains list integrity
- **Navigation at boundaries:** Displays appropriate messages
- **Current song display:** Shows meaningful feedback when no song is loaded
- **Formatted output:** Consistent use of borders (dashes) for better readability

---

##  Limitations

### Data Type Constraints

| Field | Type | Max Length | Range |
|-------|------|-----------|-------|
| Title | char | 49 chars | Any characters |
| Artist | char | 49 chars | Any characters |
| Duration | int | Not limited | 0 to 2,147,483,647 sec |

### Functional Limitations

- **Search:** Only by serial number, not by title or artist
- **Sorting:** No built-in sort functionality
- **Filtering:** Cannot filter by artist or duration
- **Editing:** Cannot modify song details after adding
- **Undo/Redo:** No operation history or undo functionality
- **Duplicate Detection:** Cannot detect duplicate songs
- **Duration Limits:** No validation for realistic duration ranges

### Technical Limitations

- **Fixed Array Sizes:** Song titles and artist names limited to 50 characters
- **Input Buffer:** Read buffer limited to 150 characters for file loading
- **Line Length:** File format requires exact CSV with commas as delimiters
- **No Encryption:** Playlist file is plain text
- **Memory:** Uses dynamic allocation; large playlists depend on available RAM
- **Platform:** Portable code, but no platform-specific optimizations

### Known Issues

1. **Search Function:** No bounds checking for out-of-range serial numbers
   - Entering a very high number may cause undefined behavior
   - No error message displayed

2. **Input Validation:** Limited validation of user input
   - Entering non-numeric values for duration may cause issues
   - Long titles/artists exceeding 49 chars are truncated silently

3. **File Format:**
   - If `playlist.txt` is corrupted (invalid format), corrupted entries are skipped
   - No validation that duration values are valid integers

4. **Edge Cases:**
   - Cannot handle empty songs gracefully
   - No warning when overwriting existing playlist data

5. **Memory Management:**
   - If `malloc()` fails mid-operation, partial data may be lost
   - No recovery mechanism for failed allocations

---

##  Future Enhancements

### High Priority

- [ ] **Edit Song Details**
  - Modify title, artist, or duration of existing songs
  - Update persistent storage automatically

- [ ] **Search Enhancements**
  - Search by song title
  - Search by artist name
  - Case-insensitive searching
  - Partial string matching

- [ ] **Input Validation**
  - Validate duration ranges
  - Check for duplicate entries
  - Limit title and artist lengths gracefully
  - Handle non-numeric input elegantly

- [ ] **Playlist Organization**
  - Sort by title, artist, or duration
  - Reverse playlist order
  - Shuffle songs
  - Remove duplicates

### Medium Priority

- [ ] **Enhanced File Management**
  - Export playlist to different formats (JSON, XML)
  - Import playlists from external files
  - Backup existing playlists
  - Multiple playlist support

- [ ] **Playback Features**
  - Repeat single song
  - Repeat all songs
  - Calculate total playlist duration
  - Show current song number and total songs

- [ ] **User Experience**
  - Keyboard shortcuts
  - Auto-play next song
  - Playlist statistics (number of songs, total duration)
  - Recently played history

- [ ] **Advanced Operations**
  - Move songs to different positions
  - Create multiple playlists
  - Merge playlists
  - Export to external player formats

### Low Priority

- [ ] **GUI Version**
  - GTK+ interface for Linux
  - Qt for cross-platform
  - Web-based interface

- [ ] **Audio Integration**
  - Actual audio playback
  - Duration calculation from audio files
  - Integration with system audio

- [ ] **Data Analytics**
  - Most played songs
  - Listening statistics
  - Favorite artists

- [ ] **Code Quality**
  - Refactor into modular functions
  - Add comprehensive comments
  - Create unit tests
  - Improve error handling

---

##  Contributing

Contributions are welcome! Here's how you can help improve the Music Playlist Manager:

### How to Contribute

1. **Fork** the repository
   ```bash
   git clone https://github.com/yourusername/music-playlist-manager.git
   ```

2. **Create** a feature branch
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Make** your changes
   - Write clean, readable code
   - Follow existing code style
   - Add comments for complex logic

4. **Test** thoroughly
   - Test with various playlist sizes
   - Check edge cases (empty playlist, single song, etc.)
   - Verify file persistence works correctly

5. **Commit** your changes
   ```bash
   git commit -m 'Add feature: detailed description'
   ```

6. **Push** to the branch
   ```bash
   git push origin feature/your-feature-name
   ```

7. **Open** a Pull Request
   - Provide clear description
   - Include examples if applicable

### Contribution Guidelines

#### Code Style
- **Indentation:** 4 spaces (no tabs)
- **Braces:** K&R style
  ```c
  if (condition) {
      // code
  }
  ```
- **Naming:**
  - Variables: `snake_case`
  - Functions: `snake_case`
  - Constants: `UPPER_CASE`
- **Comments:** Clear and concise

#### What to Contribute

**Bug Fixes:**
- Fix search function bounds checking
- Improve input validation
- Add error handling for corrupted files
- Handle memory allocation failures gracefully

**New Features:**
- Implement search by title/artist
- Add sorting functionality
- Create editing capabilities
- Implement shuffle and repeat features

**Documentation:**
- Improve README
- Add code comments
- Create tutorials
- Write test cases

### Testing Checklist

Before submitting a pull request, ensure:

- [ ] Code compiles without warnings
  ```bash
  gcc -std=c99 -Wall -Wextra music_playlist.c -o playlist
  ```
- [ ] All operations work correctly
- [ ] Edge cases handled (empty playlist, single song, etc.)
- [ ] No memory leaks (test with valgrind if available)
- [ ] File persistence works
- [ ] Navigation functions properly
- [ ] Code follows style guidelines

---

##  License

This project is licensed under the **MIT License**.

```
MIT License

Copyright (c) 2026 Music Playlist Manager Contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

### What This Means

 **You CAN:**
- Use the software for commercial purposes
- Modify the software
- Distribute the software
- Use the software privately
- Sublicense the software

 **You CANNOT:**
- Hold the author liable
- Expect warranty or guarantee

 **You MUST:**
- Include the license and copyright notice
- State changes made to the code

---

##  Contact

### Support

If you find issues or have suggestions:
- **Report Bugs:** Open an issue on GitHub
- **Request Features:** Discuss in GitHub issues
- **Contribute Code:** Submit a pull request
- **Share Feedback:** Any feedback is welcome

### Get Involved

If you find this project helpful:
-  Star the repository
-  Report bugs you discover
-  Suggest new features
-  Improve documentation
-  Contribute code improvements

---

##  Project Statistics

| Metric | Value |
|--------|-------|
| **Current Version** | 1.0.0 |
| **Development Status** | Stable |
| **Last Updated** | April 24, 2026 |
| **Lines of Code** | ~400 |
| **Language** | C (C99 standard) |
| **License** | MIT |
| **Stability** | Production Ready |
| **Platforms** | Linux/Unix/Windows |

---

##  Quick Start

```bash
# Compile
gcc -std=c99 music_playlist.c -o playlist -Wall

# Run
./playlist

# Add a song: Select option 1
# Display all: Select option 3
# Check current song: Select option 4
# Navigate: Use options 5 and 6
# Exit: Select option 8 (auto-saves)
```

---

##  Learning Resources

This project demonstrates:
- **Doubly-Linked Lists:** Dynamic data structure implementation
- **File I/O:** Reading and writing persistent data
- **Memory Management:** Dynamic allocation and deallocation
- **Pointer Arithmetic:** Navigation through linked structures
- **Menu-Driven Programming:** User interface design
- **String Handling:** Buffer management and input parsing

---

**Made with ❤️ for Music Lovers and C Enthusiasts**

*Music Playlist Manager - Your Personal DJ in the Terminal*