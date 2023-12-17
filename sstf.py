def sstf(request_queue, head_position):
    queue = sorted(request_queue)  # Sort the request queue
    seek_sequence = []
    head = head_position

    while queue:
        if queue[0] > head:
            temp = [i for i in queue if i > head]
        else:
            temp = [i for i in queue if i <= head]

        if temp:
            move = min(temp)  # Choose the request with the shortest seek time
            head = move
            queue.remove(move)  # Remove the selected request
        else:
            # If no suitable request found in the current direction, switch direction
            move = min(queue) if head <= queue[-1] else max(queue)
            head = move
            queue.remove(move)

        seek_sequence.append(head)

    return seek_sequence

if __name__ == "__main__":
    # Example input values
    request_queue = [98, 183, 37, 122, 14, 124, 65, 67]
    head_position = 53

    # Run the SSTF algorithm
    result = sstf(request_queue, head_position)

    # Print the seek sequence
    print("Seek Sequence:", result)
