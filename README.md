Redis RDB dump parser
===============

This is a work in progress. The idea is to write a streaming parser for .rdb files, using Redis' code as a base. Right now, I've modified the check-redis-dump program to print out the data in a dump file. It doesn't parse ziplists or intsets yet. It is drastically faster than any other .rdb parser I've seen, but keep in mind its highly limited feature set and weird API.
