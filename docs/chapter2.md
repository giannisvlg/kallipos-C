# Κεφάλαιο 2

# Εισαγωγικές έννοιες στον προγραμματισμό με τη C #

## 2.1 Εισαγωγή

Η C είναι μια μικρή γλώσσα και αυτό αποτελεί μια στρατηγική σχεδιαστική απόφαση των δημιουργών της. Σε αυτό το πνεύμα οι δεσμευμένες λέξεις στη C είναι σχετικά λίγες. Οι βασικές δεσμευμένες λέξεις περιλαμβάνονται στον Πίνακα 2.1(1). 
{ .annotate }

1.  Στη C υπάρχουν και άλλες δεσμευμένες λέξεις που έχουν προστεθεί κατά την εξέλιξη των προτύπων της γλώσσας (π.χ.<span class="p-style">inline</span> και <span class="p-style">restrict</span> στη C99, _StaticAssert στη C11 κ.ά.)


+---------+---------+-------------------+-------------------+-------------------+-------------------+-------------------+-------------------+
| auto    | double  | int               | struct            | break             | else              | long              | switch            |
+---------+---------+-------------------+-------------------+-------------------+-------------------+-------------------+-------------------+
| case    | enum    | register          | typedef           | char              | extern            | return            | union             |
+---------+---------+-------------------+-------------------+-------------------+-------------------+-------------------+-------------------+
| const   | float   | short             | unsigned          | continue          | for               | signed            | void              |
+---------+---------+-------------------+-------------------+-------------------+-------------------+-------------------+-------------------+
| default | goto    | sizeof            | volatile          | do                | if                | static            | while             |
+---------+---------+-------------------+-------------------+-------------------+-------------------+-------------------+-------------------+





Βασικό συστατικό τμήμα κάθε προγράμματος στη C είναι η συνάρτηση <span class="p-style">main()</span> που λειτουργεί ως σημείο εισόδου (entry point) για την εκτέλεση του προγράμματος. Η συνάρτηση <span class="p-style">main()</span> συνήθως γράφεται όπως στη συνέχεια.

```{.text .nocopy}
int main(void) {
    // Ο κώδικας του προγράμματος τοποθετείται εδώ
    return 0;
}
```
To <span class="p-style">void</span> εντός των παρενθέσεων της <span class="p-style">main()</span>, στη γραμμή 1, υποδηλώνει ότι η <span class="p-style">main()</span> δεν δέχεται παραμέτρους. Ωστόσο, η <span class="p-style">main()</span> μπορεί να γραφεί και ως <span class="p-style">int main(int argc, char *argv[])</span> έτσι ώστε να δέχεται ορίσματα γραμμής εντολών όπως θα δούμε στο Κεφάλαιο 6. Το σώμα της συνάρτησης <span class="p-style">main()</span>, δηλαδή ότι περιέχεται ανάμεσα στις αγκύλες μετά το <span class="p-style">main()</span>, περιέχει τον κώδικα που θα εκτελεστεί, άρα εκείκαθορίζεται η ροή εκτέλεσης του προγράμματος. Στη γραμμή 2 του κώδικα υπάρχει ένα σχόλιο που η αρχήτου υποδηλώνεται με το //. Η εντολή <span class="p-style">return</span> στο τέλος της <span class="p-style">main()</span> χρησιμοποιείται για να καθορίσει την κατάσταση του προγράμματος κατά την έξοδο, δηλαδή αν το πρόγραμμα επιτέλεσε σωστά τις λειτουργίες του ή αν προκλήθηκε κατά την εκτέλεση κάποια «μη φυσιολογική» κατάσταση. Η επιστροφή της τιμής 0 συμβατικά υποδηλώνει την επιτυχή εκτέλεση, ενώ μη μηδενικές τιμές υποδηλώνουν ότι το πρόγραμμα τερματίστηκε ανώμαλα.



## 2.2 Τύποι δεδομένων και μεταβλητές

```{.c title="ch2_p1.c" linenums="1"}
--8<-- "src/ch2_p1.c"
```

```{.text .nocopy}
$ gcc ch2_p1.c -o ch2_p1 -Wall -Wextra -pedantic -std=c17
$ ./ch2_p1
int (4 bytes)           -2147483648 to 2147483647
double (8 bytes)        2.225074e-308 to 1.797693e+308
```

## 2.5 Είσοδος / Έξοδος

### 2.5.1 Η συνάρτηση printf()

```{.c title="ch2_p2.c" linenums="1"}
--8<-- "src/ch2_p2.c"
```

```{.text .nocopy}
$ gcc ch2_p2.c -o ch2_p2 -Wall -Wextra -pedantic -std=c17
$ ./ch2_p2
This string contains newline characters 
New Line
This string contains a tab character    Tabbed Text
This string contains a backslash character \
This string contains "Double Quotes"
This string contains 'Single Quotes'
This string contains backspace characters:Learn plain C
This string makes a beep sound
This string contains a hexadecimally encoded symbol √
This string contains the NULL character
```

```{.c title="ch2_p3.c" linenums="1"}
--8<-- "src/ch2_p3.c"
```

```{.c title="ch2_p4.c" linenums="1"}
--8<-- "src/ch2_p4.c"
```

### 2.5.2 Η συνάρτηση scanf()
```{.c title="ch2_p5.c" linenums="1"}
--8<-- "src/ch2_p5.c"
```

### 2.5.3 Ιδιαιτερότητες της scanf() και άλλες συναρτήσεις εισόδου/εξόδου
```{.c title="ch2_p6.c" linenums="1"}
--8<-- "src/ch2_p6.c"
```

```{.c title="ch2_p7.c" linenums="1"}
--8<-- "src/ch2_p7.c"
```

#### Διαδοχικές scanf()
```{.c title="ch2_p8.c" linenums="1"}
--8<-- "src/ch2_p8.c"
```

#### Οι συναρτήσεις getc() και putc()
```{.c title="ch2_p9.c" linenums="1"}
--8<-- "src/ch2_p9.c"
```

## 2.6 Τελεστές

### 2.6.2 Αριθμητικοί τελεστές
```{.c title="ch2_p10.c" linenums="1"}
--8<-- "src/ch2_p10.c"
```

```{.c title="ch2_p11.c" linenums="1"}
--8<-- "src/ch2_p11.c"
```

### 2.6.3 Συγκριτικοί τελεστές
```{.c title="ch2_p12.c" linenums="1"}
--8<-- "src/ch2_p12.c"
```

### 2.6.4 Λογικοί τελεστές
```{.c title="ch2_p13.c" linenums="1"}
--8<-- "src/ch2_p13.c"
```

### 2.6.5 Τελεστές χειρισμού δυαδικών ψηφίων
```{.c title="ch2_p14.c" linenums="1"}
--8<-- "src/ch2_p14.c"
```

#### 2.6.5.1 Μάσκες δυαδικών ψηφίων
```{.c title="ch2_p15.c" linenums="1"}
--8<-- "src/ch2_p15.c"
```

### 2.6.6 Τελεστές μετατροπής τύπων
```{.c title="ch2_p16.c" linenums="1"}
--8<-- "src/ch2_p16.c"
```

### 2.6.7 Άλλοι τελεστές
```{.c title="ch2_p17.c" linenums="1"}
--8<-- "src/ch2_p17.c"
```

```{.c title="ch2_p18.c" linenums="1"}
--8<-- "src/ch2_p18.c"
```

```{.c title="ch2_p19.c" linenums="1"}
--8<-- "src/ch2_p19.c"
```

## 2.8 Κύκλος μεταγλώττισης, σύνδεσης και εκτέλεσης

```{.c title="ch2_p20.c" linenums="1"}
--8<-- "src/ch2_p20.c"
```

<!-- ## 2.9 Ασκήσεις

***Άσκηση 1***
```{.c title="ch2_e1.c" linenums="1"}
--8<-- "src/ch2_e1.c"
```

***Άσκηση 2***
```{.c title="ch2_e2.c" linenums="1"}
--8<-- "src/ch2_e2.c"
```

***Άσκηση 3***
```{.c title="ch2_e3.c" linenums="1"}
--8<-- "src/ch2_e3.c"
```

***Άσκηση 4***
```{.c title="ch2_e4.c" linenums="1"}
--8<-- "src/ch2_e4.c"
```

***Άσκηση 5***
```{.c title="ch2_e5.c" linenums="1"}
--8<-- "src/ch2_e5.c"
```
 -->

[^1]: This is a test !