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