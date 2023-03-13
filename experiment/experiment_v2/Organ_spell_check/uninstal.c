static int confirm (void) {
    char answer [10];
    fflush (stdout);
    return (scanf (" %c", answer) == 1 && toupper (answer[0]) == 'Y');
}

