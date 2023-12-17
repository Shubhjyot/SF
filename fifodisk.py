def fifo(request_queue, head_position):
    seek_sequence = []
    head = head_position
    total_seek_time = 0

    for request in request_queue:
        seek_sequence.append(head)
        total_seek_time += abs(head - request)
        head = request

    # Include the last head position in the seek sequence
    seek_sequence.append(head)

    # Calculate the seek time for the last request
    total_seek_time += abs(head - request_queue[-1])

    return seek_sequence, total_seek_time

if __name__ == "__main__":
    # Example input values
    request_queue = [98, 183, 37, 122, 14, 124, 65, 67]
    head_position = 53

    # Run the FIFO algorithm
    result, total_seek_time = fifo(request_queue, head_position)

    # Print the seek sequence and total seek time
    print("Seek Sequence:", result)
    print("Total Seek Time:", total_seek_time)
