void display() {
    int i;
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++) {  // Loop from front to rear
            printf("%d\n", queue[i]);
        }
    }
}
