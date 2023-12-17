# def look_disk_scheduling(requests, start_direction="left"): 
#     seek_count = 0
#     current_track = 0
    
#     if start_direction == "left":
#         requests.sort()
#     else:
#         requests.sort(reverse=True)
        
#     for request in requests:
#         seek_count += abs(current_track - request)
#         current_track = request
    
#     return seek_count

# # Example Usage
# requests = [98, 183, 37, 122, 14, 124, 65, 67]
# look_result = look_disk_scheduling(requests, start_direction="left")
# print(f"Look Disk Scheduling Seek Count: {look_result}")


def LOOK(arr, head, direction):
    total_distance = 0
    size = len(arr)

    visited = [0] * size

    # Sorting disk locations
    arr.sort()

    # Finding the position of the head in sorted array
    for i in range(size):
        if arr[i] > head:
            left = i - 1
            right = i
            break

    # LOOK in the left direction
    for i in range(left, -1, -1):
        current = arr[i]
        visited[i] = 1
        distance = abs(current - head)
        total_distance += distance
        head = current

    # LOOK in the right direction
    for i in range(right, size):
        current = arr[i]
        visited[i] = 1
        distance = abs(current - head)
        total_distance += distance
        head = current

    print("Seek Sequence:", arr)
    print("Total Head Movement:", total_distance)


if __name__ == "__main__":
    n = int(input("Enter the number of disk requests: "))
    arr = list(map(int, input("Enter the disk requests: ").split()))
    head = int(input("Enter the initial position of the disk head: "))
    direction = input("Enter the direction (L/R): ")

    LOOK(arr, head, direction)

