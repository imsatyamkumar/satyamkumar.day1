from collections import deque

class LiftManagement:
    def __init__(self, total_floors):
        self.queue = deque()        # To store the requests in a queue
        self.current_floor = 0      # Lift starts at ground floor (0)
        self.total_floors = total_floors

    def request_lift(self, request_floor):
        if 0 <= request_floor < self.total_floors:
            self.queue.append(request_floor)
            print(f"Request for floor {request_floor} added to queue.")
        else:
            print("Invalid floor request.")

    def move_lift(self):
        while self.queue:
            next_floor = self.queue.popleft()  # FIFO - Serve the next request
            self.move_to_floor(next_floor)
        print("No more requests. Lift is idle.")

    def move_to_floor(self, next_floor):
        print(f"Moving from floor {self.current_floor} to floor {next_floor}.")
        self.current_floor = next_floor
        print(f"Lift has arrived at floor {self.current_floor}.")

    def show_queue(self):
        if self.queue:
            print("Current requests in queue:", list(self.queue))
        else:
            print("No requests in the queue.")

# Example usage:
if __name__ == "__main__":
    lift = LiftManagement(total_floors=10)  # Building with 10 floors

    # People making requests
    lift.request_lift(3)
    lift.request_lift(7)
    lift.request_lift(2)

    # Display current queue
    lift.show_queue()

    # Moving the lift to serve all requests
    lift.move_lift()

    # Display queue after serving all requests
    lift.show_queue()
