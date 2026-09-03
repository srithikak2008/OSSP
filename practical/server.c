    // Set socket address
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, SOCKET_PATH);

    // Remove old socket
    unlink(SOCKET_PATH);

    // Bind socket to path
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // Wait for client
    listen(server_fd, 5);

    printf("Server waiting...\n");

    // Accept client
    client_fd = accept(server_fd, NULL, NULL);

    // Receive message
    read(client_fd, buffer, sizeof(buffer));

    printf("Message from client: %s\n", buffer);

    close(client_fd);
    close(server_fd);

    unlink(SOCKET_PATH);

    return 0;
}
