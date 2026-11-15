# Left Movement Tests

- Tested before random insertion, with insert_random commented out

Starting: 0 2 0 2 0; Expected: 4 0 0 0 0; Result: 4 0 0 0 0; Passed.
Starting: 2 2 2 0 0; Expected: 4 2 0 0 0; Result: 4 2 0 0 0; Passed.
Starting: 2 2 2 2 2; Expected: 4 4 2 0 0; Result: 4 4 2 0 0; Passed.
Starting: 2 2 4 0 0; Expected: 4 4 0 0 0; Result: 4 4 0 0 0; Passed.
Starting: 4 4 8 8 0; Expected: 8 16 0 0 0; Result: 8 16 0 0 0; Passed.
Starting: 2 4 8 0 0; Expected: 2 4 8 0 0; Result: 2 4 8 0 0; Passed.

# Scoring Tests

- Scoring was tested for multiple merges and an unchanged move.

Starting: 4 4 8 8 0, Score: 0; Move: left; Expected: 8 16 0 0 0, Score 24; Actual 8 16 0 0 0, Score 24; Passed.
Starting: 8 16 0 0 0, Score: 24; Move: left; Expected: no change, Score 24; Actual: no change, Score 24; Passed.

# Moves Tests

Starting: 4 4 8 8 0, Score: 0, Moves: 0; Input: l; Expecting: 8 16 0 0 0, Score: 24, Moves: 1; Actual: 8 16 0 0 0, Score 24, Moves 1; Passed.
Input 1 again; Expected: no change, Score: 24, Moves: 1; Actual: no change, Score: 24, Moves: 1; Passed.

# Random Insertion Tests

Successful Move: Starting: 4 4 8 8 0, other rows 0; Expected: 8 16 0 0 0, Random 2, Score: 24, Moves: 1; Actual: 8 16 0 0 0, Random 2 in row 3 col 5, Score: 24, Moves: 1; Passed.
No Change: Starting: 2 4 8 0 0, other rows 0; Expected: same board, no random, Score: 0, Moves: 0; Actual: same board, no random, Score: 0, Moves: 0; Passed.
Starting: 0 2 0 4 0, other rows 0, Score: 0; Moves: 0; Input: 1; Expected: 2 4 0 0 0, Random 2, Score: 0, Moves: 1; Actual: 2 4 0 0 0, Random 2 in row 3 col 5, Score: 0, Moves: 1; Passed.

# Right Movement Tests
With the other rows empty and random insertion disabled, each test starts with score 0 and moves 0.

Starting: 2 2 2 0 0; Expected: 0 0 0 2 4; Actual: 0 0 0 2 4; Score: 4; Moves: 1; Passed.
Starting: 2 0 2 0 4; Expected: 0 0 0 4 4; Actual: 0 0 0 4 4; Score: 4; Moves: 1; Passed.
Starting: 2 2 2 2 2; Expected: 0 0 2 4 4; Actual: 0 0 2 4 4; Score: 8; Moves: 1; Passed.
Starting: 0 0 2 4 8; Expected: no change; Actual: no change; Score 0; Moves 0; Passed.

# Up Movement Tests
First Column, values listed from top to bottom. All other cells are zero. Random insertion is disabled and each test starts with score 0 and moves 0.

Starting: 2 2 2 0 0; Expected: 4 2 0 0 0, score 4, moves 1; Actual: 4 2 0 0 0, score 4, moves 1; Passed.
Starting: 4 0 2 0 2; Expected: 4 4 0 0 0, score 4, moves 1; Actual: 4 4 0 0 0, score 4, moves 1; Passed.
Starting: 2 2 2 2 2; Expected: 4 4 2 0 0, score 8, moves 1; Actual: 4 4 2 0 0, score 8, moves 1; Passed.
Starting: 2 4 8 0 0; Expected: no change, score 0, moves 0; Actual: no change, score 0, moves 0; Passed.

# Down Movement Tests
First Column, values listed from top to bottom. All other cells are zero. Random insertion is diabled and each test starts with score 0 and moves 0.

Starting: 2 2 2 0 0; Expected: 0 0 0 2 4, score 4, moves 1; Actual: 0 0 0 2 4, score 4, moves 1; Passed.
Initial test: 2 0 2 0 4; Expectd: 0 0 0 4 4, score 4, moves 1; Actual: 0 0 0 0 8, score 12, moves 1; Failed.
- Correction: An extra row loop was causing each column to process five times. Seperated the starting board bopy from the movement loop and added the missing copy into starting.
Retest: 0 0 0 4 4, score 4, moves 1; Passed.
Starting: 2 2 2 2 2; Expected: 0 0 2 4 4, score 8, moves 1; Actual: 0 0 2 4 4, score 8, moves 1; Passed.
Starting: 0 0 2 4 8; Expected: no change; Actual; no change, score 0, moves 0; Passed.

# Initialize New Game
Expected: two random 2s in different cells, all others 0, score 0, moves 0; Actual: As Expected; Passed.

# Confirm New Game
Input: n, then y; Expected: two 2s in different cells, all other cells 0, score 0, moves 0; Actual: As Expected; Passed.

# Cancel New Game
Input: n, then n; Expected: no change to board, score, and moves; Actual: As Expected; Passed.

# Help Menu
Input: h; Expected: help menu displays while the board, score, and moves are unchanged; Actual: As Expected; Passed.

# Invalid Command
Input: p; Expected: error message and no change to board, score, and moves; Actual As Expected; Passed.

# Exit
Input: e; Expected: program ends; Actual: program ends; Passed.

# End Input
Input: Control+D; Expected: program ends; Actual: program ends; Passed.

# Highest Tile
Initial Start Expected: score 0, move 0, highest tile 2; Actual: score 0, move 0, highest tile 2; Passed.
Input: merge two 2 tiles; Expected: score 4, move 2, highest tile 4; Actual score 4, move 2, highest tile 4; Passed.

# Win Message
First row, first and second column set to 1024 for test of win message.
Input: l; Expected: win message displayed; Actual: win message displayed; Passed.

# Game-Over
Full board of alternating 2s and 4s for test.
Input: l; Expected: game-over message, unchanged board, score 0, move 0; Actual: As Expected; Passed.

# Help Menu - Post Game-Over
Input: h; Expected: help menu displayed, game remains open; Actual: As Expected; Passed.

# Full-board Merge
First row 2 2 2 4 2 for test.
Input: l; Expected: first row 4 2 4 2 2, score 4, moves 1, no game over; Actual: As Expected; Passed.

# Save Game
Input: s after play; Expected: savegame.txt with format label, current score, moves, and all 25 tiles, game unchanged; Actual: As Expected; Passed.
-Overwrite Save
Input: move, s; Expected: same file updated with new board values, score, and moves; Actual: As Expected; Passed.

# Load Game
Input: s, make move, then o; Expected: Previously saved board; Actual: As Expected; Passed.
t
# Invalid Save
Changed label to wrong_label; Expected: failed load message, game unchanged; Actual: As Expected; Passed.
Added a negative value (-1); Expected: failed load message, game unchanged; Actual: As Expected; Passed.
Added an invalid value (3); Expected: failed load message, game unchanged; Actual: As Expected; Passed.
Added extra data in the last row (99); Expected: failed load message, game unchanged; Actual: As Expected; Passed.
Removed a tile; Expected: failed load message, game unchanged; Actual: As Expected; Passed.