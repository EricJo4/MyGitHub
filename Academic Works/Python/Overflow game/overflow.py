# copy over your a1_partd.py file here
from lists import Queue

# Function to get the list of overflowing cells in the grid
def get_overflow_list(grid):
    overflow_list = []
    max_row = len(grid) - 1
    max_col = len(grid[0]) - 1

    for row in range(len(grid)): #Iterate through rows
        for col in range(len(grid[0])): #Iterate through columns
            if (row == 0 and col == 0) or (row == 0 and col == max_col) or (row == max_row and col == 0) or (row == max_row and col == max_col):             # Determine the number of neighbors based on the position of the cell
                neighbors = 2
            elif row == 0 or row == max_row or col == 0 or col == max_col:
                neighbors = 3
            else:
                neighbors = 4

            # Check if the cell is overflowing
            if abs(grid[row][col]) >= neighbors:
                overflow_list.append((row, col))

    return overflow_list if overflow_list else None

# Function to process the grid overflow
def overflow(grid, a_queue):
    if a_queue is None:
        a_queue = Queue()
        a_queue.enqueue([row[:] for row in grid])  # Enqueue the initial grid if nothing is passed in.

    # Check if the grid is not overflowing (all cells have the same sign)
    if all(cell >= 0 for row in grid for cell in row) or all(cell <= 0 for row in grid for cell in row):
        return 0 #Return 0 since if the grid is not overflowing, we don't want to add any steps.
    
    initial_overflows = get_overflow_list(grid)
    if initial_overflows is None:
        return 0 #Return 0 since if the grid is not overflowing, we don't want to add any steps.

    new_grid = [row[:] for row in grid]  # Deep copy of the grid. We can't change the original grid just yet because we need to refer back to it later.
    for i, j in initial_overflows:
        new_grid[i][j] = 0  # Set overflowing cells to zero

    for i, j in initial_overflows:
        sign = -1 if grid[i][j] < 0 else 1 #We refer back to the original grid here, since we've already set overflowing cells to 0 in the new grid
        # Update the neighbors of all overflowing cells
        for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ni, nj = i + di, j + dj
            if 0 <= ni < len(grid) and 0 <= nj < len(grid[0]):
                new_grid[ni][nj] = abs(new_grid[ni][nj]) + 1  # Increment the absolute value by 1
                new_grid[ni][nj] *= sign  # Apply the sign of the overflowing cell

    grid[:] = new_grid  # Update the original grid with the new grid
    a_queue.enqueue([row[:] for row in grid])  # Enqueue the new grid

    return overflow(grid, a_queue) + 1  # Recursive call and increment step count. The deepest layer of recursion always returns 0, to ensure that if the grid starts out non-overflowing, 0 is returned. Each recursion depth then returns +1 on top of the deeper layer to account for the number of steps needed to reach the final state.
