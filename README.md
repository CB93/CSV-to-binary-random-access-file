# CSV-to-binary-random-access-file

## Create.exe
Create.exe is a program that reads a .CSV file, parses each line, and populates an appropriately defined struct of mock
banking imformation. Followed by this, each struct is stored into an array and written to a .DAT file in binary format, overwriting
the file if it exists.

The filenames must be passed to the program via command line arguments.
For simplicity, both files reside in the program’s current directory.

### Example:
```
Create.exe sourcefilename destinationfilename
```

## Display.exe
Diplay.exe reads the data file generated in Create.exe then displays the data to the screen.

These filenames must also be passed to the program via command line arguments.
### Example:
```
Display.exe sourcefilename
```

## CSV format

Each CSV file line contains five fields:

• AccountNumber
• FirstName
• LastName
• AccountBalance
• LastPaymentAmount

## CSV file line example:

```
1001, Cosmo, Kramer, 5827.48, 1500.00
```


