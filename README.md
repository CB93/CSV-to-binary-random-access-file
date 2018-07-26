# CSV-to-binary-random-access-file


Create.c is program that reads a CSV file, parses each line, populates an appropriately defined struct and
writes the struct to a file in binary format (.dat format) ,over writing the file if it exists.

The filenames must be passed to the program via command line arguments.
For simplicity, both files reside in the program’s current directory.

### Example:
```
exename sourcefilename destinationfilename
```

## CSV format

Each CSV file line contains five fields:
• AccountNumber\n
• FirstName\n
• LastName
• AccountBalance
• LastPaymentAmount

# CSV file line example:

```
1001, Cosmo, Kramer, 5827.48, 1500.00
```


