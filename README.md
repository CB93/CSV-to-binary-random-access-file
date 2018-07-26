"# CSV-to-binary-random-access-file" 


Create.c is program that reads a CSV file, parses each line, populates an appropriately defined struct and
writes the struct to a file in binary format (.dat format) ,over writing the file if it exists.


Each CSV file line contains five fields:
• AccountNumber
• FirstName
• LastName
• AccountBalance
• LastPaymentAmount

You can assume that the file format is always correct (minimal validation required).

CSV file line example:

1001, Cosmo, Kramer, 5827.48, 1500.00

The filenames will be passed to the program via command line arguments.
For simplicity, have both files reside in the program’s current directory.
Example:
exename sourcefilename destinationfilename
