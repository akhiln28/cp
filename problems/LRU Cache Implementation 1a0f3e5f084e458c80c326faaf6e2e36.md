# LRU Cache Implementation

Created Time: Jan 24, 2021 6:50 PM
Do Date: Jan 24, 2021
Last edited time: May 11, 2021 8:58 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Hashing-dc1f706a2c0b4b5eb6ee200a3ab1ae98
Points: 1500
Status: ok

For implementing LRU cache. Use the following 

1. A doubly linked list for storing the order (Most recently used at the front and least recently used at the back)
2. And hash table for storing the key (page) and value (pointer to node in linked list)