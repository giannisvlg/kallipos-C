# 18. Θέματα στυλ στη C

<i>Σύνοψη</i> O ελεύθερος τρόπος γραφής προγραμμάτων στη C και τα προβλήματα που δημιουργεί, κανόνες στυλ, το clang-format για εύκολη μορφοποίηση κώδικα C, άλλα εργαλεία μορφοποίησης και ωραιοποίησης κώδικα, ιδιωματικός κώδικας στη C.  

<i>Προαπαιτούμενη γνώση</i> Τύποι δεδομένων, είσοδος/έξοδος, δομές επιλογής και επανάληψης, συναρτήσεις, πίνακες, δείκτες, αλφαριθμητικά, διαμερισμός κώδικα, ορίσματα γραμμής εντολών.

## 18.1 Εισαγωγή

Η C δίνει τη δυνατότητα στους προγραμματιστές να γράφουν με οποιαδήποτε μορφή τον κώδικά τους, αρκεί να μην παραβιάζονται οι συντακτικοί κανόνες της γλώσσας. Αυτό δίνει μεγάλη ελευθερία στη μορφή που μπορεί να έχει ο κώδικας. Έτσι κώδικας όπως ο ακόλουθος είναι έγκυρος.

```
int*d,D[9999],N=20,L=4,n,m,k,a[3],i;char*p,*q,S[2000]="L@X‐SGD‐HNBBB‐AD‐VHSG‐\
‐XNT\x1b[2J\x1b[H",*s=S,*G="r2zZX!.+@KBK^yh.!:%Bud!.+Jyh.!6.BHBhp!6.BHBh!:%Bu\
v{VT!.hBJ6p!042ljn!284b}`!.hR6Dp!.hp!h.T6p!h.p6!2/LilqP72!h.+@QB!~}lqP72/Lil!\
h.+@QBFp!:)0?F]nwf!,82v!.sv{6!.l6!,j<n8!.xN6t!&NvN*!.6hp";/*Stay_on_target.**/
#include/**/<complex.h>/**//*Oh,my_dear_friend.How_I've_missed_you.‐‐C‐3PO***/
typedef/**/complex/**/double(c);c(X)[3],P,O;c/**/B(double t){double s=1‐t,u;P=
s*s*X[1]            +2        *s*t*        *X+t        *t*X       [2]+O;u=I*P;
return+48*((    s=P)+   48*I   )/(   1<u?   u:   1);}   /*   1977  IOCCC2020*/
#include/**    Do.Or   do_not   .   There_is_   no_try...   ‐‐Yoda**/<stdio.h>
void/**/b(    double   t,/***   *   **/double   u){double   s=P=B(t)‐B(u);(s=P
*(2*s‐P))    <1?m=P=B   ((t+   u)/   2),k   =‐   I*P,   m>   ‐41&&m<39&&9<k&&k
<48?               m+=k/      2*80+        73,S        [m]=               S[m]
‐73?k%2?S[m]‐94?95:73:S[m]‐95?94:73:73:1:(b(t,(t+u)/2),b((t+u)/2,u),0);}/*<oo>
_No.             _I_am_            IOCCC           1977                   ***/
#include/*****    your   father..   ‐‐DarthVader   **/   <time.h>/****   ****/
int(main)(int    (x),   char**V){;   clock_t(c)=   /*   */clock();;;   for(d=D
;m<26;m++,s    ++)*s>   63?*d++=m%   7*          16‐7   *8,*d++=m/   7*25,*d++
=*s‐64:0;;    if(V[1])   {;;;FILE   *F   =fopen(V[+1],   "r");for   (d=D,L=N=m
=0;(x=/**             *            ***              **/            fgetc(F))>0
||fclose(F);)if(x>13?64<x&&x<91?*d++=m*16,*d++=L*25,*d++=x%26:0,m++,0:1)for(++
L;d‐D>N*3||(m=0);N++)D[N*3]‐=m*8;}for(;i<200+L*25;i++){for(n=0,p=S+33;n<1920;*
p++=n++%80>78?10:32){}for(*p=x=0,d=D;x<N;x++,d+=3){O=(d[1]‐i‐40)*I+*d;n=d[2];p
=G;for(;n‐‐;)for(;*p++>33;);*a=a[1]=*p++;for(;*p>33;p++)if(*p%2?*a=*p,0:1){a[2
]=*p;for(m=0;m<3;m++){k=a[m]/2‐18;q="/&&&##%%##.+),A$$$$ '&&'&&((%‐((#'/#%%#&#\
&&#D&";for(n=2;k‐‐;)n+=*q++‐34;X[m]=n%13+n/13*I;}b(0,1);*a=a[1]=*p;}}for(puts(
s),s=S+30;(clock()‐c)*10<i*CLOCKS_PER_SEC;);}return 0;}/*Nevertellmetheodds*/
```

Κώδικας από τον 27ο διεθνή διαγωνισμό obfuscated C code (1).
{ .annotate }

1. https://www.ioccc.org/2020/endoh2/index.html


Ένα κοινό στυλ γραφής προγραμμάτων καθιστά ευκολότερη τη συνεργασία πολλών προγραμματιστών στην από κοινού ανάπτυξη ενός λογισμικού. Έτσι θέματα όπως το εάν τοποθετούνται κενά πριν και μετά τους δυαδικούς τελεστές, πού τοποθετείται το <span class="p-style">*</span> στη δήλωση δεικτών (κολλητά στον τύπο ή κολλητά στη μεταβλητή), αν χρησιμοποιούνται στηλοθέτες ή κενά (tabs or spaces), πού τοποθετείται η αγκύλη που ορίζει την αρχή της επανάληψης (στην ίδια γραμμή με την εντολή επανάληψης ή στην αμέσως επόμενη), μπορούν να αποτελέσουν πηγή διαφωνιών και προβλημάτων.  
Γενικότερα, η υιοθέτηση κανόνων διευκολύνει την αναγνωσιμότητα και τη συντήρηση του κώδικα. Υπάρχουν λογισμικά όπως το clang-format που επιτρέπουν την αυτόματη μορφοποίηση του κώδικα σύμφωνα με στυλιστικές αποφάσεις που μπορούν να παραμετροποιηθούν. Πριν αναφερθούμε στο clang-format θα παρουσιαστούν ορισμένοι απλοί κανόνες στυλ.


## 18.2 Απλοί κανόνες στυλ

Η υιοθέτηση ενός καλού προγραμματιστικού στυλ μειώνει τα λάθη και ενισχύει την ανάπτυξη συνεπούς μορφής κώδικα που διαβάζεται εύκολα. Υπάρχουν πολλές πηγές που περιγράφουν τρόπους για να συμβεί αυτό όπως οι [^1], [^2] και [^3].  

Στη συνέχεια θα παρατεθούν ορισμένοι κανόνες που σχετίζονται με το καλό προγραμματιστικό στυλ.

1. Διατήρηση με συνέπεια του ίδιου στυλ εσοχών, τοποθέτησης αγκυλών και χρήσης κενών σε όλο τον κώδικα. Για παράδειγμα υπάρχουν τα στυλ GNU, K&R, 1TBS (One True Base Style) και άλλα. Ακολουθούν παραδείγματα μορφοποίησης ενός κώδικα με τα τρία στυλ που αναφέρθηκαν:

    === "Στυλ GNU"

        ```c
        int main (void)
        {
            ...
            while (x == y)
            {
                do_something1 ();
                if (a_condition)
                {
                    do_something2 ();
                }
                else
                {
                    do_something3 ();
                }
            }
            do_something4 ();
            ...
        }
        ```

    === "Στυλ K&R"

        ``` c
        int main(void)
        {
            ...
            while (x == y) {
                do_something1();
                if (a_condition)
                    do_something2();
                else
                    do_something3();
            }
            do_something4();
            ...
        }
        ```

    === "Στυλ 1TBS"

        ``` c
        int main(void) {
            ...
            while (x == y) {
                do_something1();
                if (a_condition) {
                    do_something2();
                } else {
                    do_something3();
                }
            }
            do_something4();
            ...
        }  
        ```
    Παρατηρήστε ότι στο στυλ K&R, αν ένα μπλοκ κώδικα έχει μια μόνο εντολή, δεν χρησιμοποιούνται αγκύλες για να το περικλείουν.

2. Χρήση επαρκώς περιγραφικών ονομάτων (π.χ. μεταβλητών, σταθερών, συναρτήσεων) που συνεισφέρουν στην εύκολη κατανόηση του κώδικα. Τα ονόματα θα πρέπει να αποδίδουν τον ρόλο της οντότητας που αναπαριστούν. Ονόματα συντομογραφίες ή μακροσκελή ονόματα συνήθως δεν είναι καλές επιλογές, ενώ το μήκος των ονομάτων θα πρέπει να είναι ανάλογο της εμβέλειάς τους. Έτσι, είναι αποδεκτό ως όνομα μεταβλητής για παράδειγμα το <span class="p-style">i</span> αν πρόκειται για τη μεταβλητή επανάληψης μιας εντολής <span class="p-style">for</span>.

3. Συγγραφή ονομάτων με ένα στυλ. Τα δύο κύρια στυλ συγγραφής ονομάτων είναι το <span class="p-style">snake_case</span> και το <span class="p-style">PascalCase</span>. Για παράδειγμα, μια μεταβλητή για το πλήθος των κερδισμένων παιχνιδιών ενός παίκτη μπορεί να ονομαστεί ακολουθώντας το πρώτο στυλ ως <span class="p-style">player_games_won</span>, ενώ ακολουθώντας το δεύτερο στυλ μπορεί να ονομαστεί ως <span class="p-style">PlayerGamesWon</span>.

4. Χρήση σχολίων στον κώδικα που να βοηθούν ουσιαστικά στην κατανόηση του κώδικα. Τα σχόλια πρέπει να μην είναι περιγράφουν κάτι που είναι προφανές, να είναι κατανοητά, να είναι ενημερωμένα και σε καμία περίπτωση να μη βρίσκονται σε αντίφαση με τον κώδικα. Για παράδειγμα, συνηθίζεται να τοποθετείται πάνω από συναρτήσεις ένα σχόλιο πολλών γραμμών που να επεξηγεί τη λειτουργία της
συνάρτησης. Ο κώδικας 18.1 περιέχει ένα παράδειγμα αυτής της μορφής σχολίου.
```{.c title="Κώδικας 18.1: ch18_p1.c - σχόλιο πολλών γραμμών με την περιγραφή της λειτουργικότητας, των εισόδων και των εξόδων μιας συνάρτησης." linenums="1"}
--8<-- "src/ch18_p1.c"
```

5. Κάθε συνάρτηση πρέπει να εκτελεί μια λειτουργία και να είναι μικρού μεγέθους.

## 18.3 clang-format

Το clang-format (<a href="https://clang.llvm.org/docs/ClangFormat.html" target="_blank">https://clang.llvm.org/docs/ClangFormat.html</a>) είναι ένα λογισμικό μορφοποίησης κώδικα που επιτρέπει την εφαρμογή καθιερωμένων προγραμματιστικών στυλ κατά την ανάπτυξη κώδικα. Προγραμματιστές που αποτελούν μέλη μιας ομάδας ανάπτυξης λογισμικού μπορούν να επωφεληθούν από το clang-format έτσι ώστε ο κώδικας που αναπτύσσουν να έχει κοινό στυλ. Οι επιμέρους ρυθμίσεις του αποθηκεύονται σε ένα αρχείο τύπου <span class="p-style">YAML</span> (Yet Another Markup Language) με όνομα <span class="p-style">.clang‐format</span> ενώ IDEs όπως το VSCode χρησιμοποιούν αυτές τις ρυθμίσεις και πραγματοποιούν αυτόματες μορφοποιήσεις.  
To clang-format είναι τμήμα του LLVM project και υποστηρίζει τη μορφοποίηση κώδικα που γράφεται και σε άλλες γλώσσες προγραμματισμού, πέρα από τη C, όπως η C++, Java, JavaScript, JSON, Objective-C, Protobuf και C#.  

<i><span class="p-style">Εγκατάσταση του Clang-Format</span></i> Η εγκατάσταση του clang-format γίνεται ως εξής:

 * Windows, υποθέτοντας ότι έχει ήδη εγκατασταθεί το λογισμικό διαχείρισης πακέτων λογισμικού chocolatey (1): <span class="p-style">choco install llvm</span>
    { .annotate }

    1. <a href="https://chocolatey.org/" target="_blank">https://chocolatey.org/</a>  

 * Windows WSL (Ubuntu): <span class="p-style">sudo apt install clang‐format</span>
 * Linux Ubuntu: <span class="p-style">sudo apt install clang‐format</span>
 * MacOS: <span class="p-style">brew install clang‐format</span>  

Ο έλεγχος της ορθής εγκατάστασης γίνεται πληκτρολογώντας <span class="p-style">clang‐format ‐‐version</span> στη γραμμή  εντολών, οπότε και θα πρέπει να επιστραφεί η έκδοση του clang-format (π.χ. clang-format version 16.0.5).


<i><span class="p-style">Προκαθορισμένα στυλ κώδικα στη C</span></i> Υπάρχουν προκαθορισμένα στυλ που μπορούν να χρησιμοποιηθούν με το clang-format. Τα στυλ αυτά έχουν δημιουργηθεί και συνεχίζουν να αναπτύσσονται από εταιρείες ή οργανισμούς. Τα στυλ που υποστηρίζει το clang-format είναι τα: LLVM, GNU, Google, Chromium, Microsoft, Mozilla και Webkit.

Η κλήση του clang-format από τη γραμμή εντολών γίνεται προσδιορίζοντας με τον διακόπτη <span class="p-style">‐‐style</span> το όνομα του προκαθορισμένου στυλ. Για παράδειγμα η ακόλουθη κλήση του clang-format θα μετατρέψει το <span class="p-style">test.c</span> σύμφωνα με το στυλ <span class="p-style">llvm</span>:

```
$ clang‐format ‐style=llvm test.c
```

Αν οι αλλαγές δεν επιθυμούμε να επηρεάσουν το αρχείο <span class="p-style">test.c</span> τότε η εντολή δέχεται επιπλέον τον διακόπτη <span class="p-style">‐‐dry‐run</span>. Περισσότερες πληροφορίες για τους διακόπτες του clang-format εμφανίζονται καλώντας το με τον διακόπτη <span class="p-style">‐‐help</span>  
Ωστόσο, η συνηθισμένη πρακτική είναι να δημιουργηθεί ένα αρχείο <span class="p-style">.clang‐format</span> χρησιμοποιώντας ως βάση ένα από τα προκαθορισμένα στυλ και στη συνέχεια να γίνουν τυχόν αλλαγές σε αυτό έτσι ώστε να ταιριάζει στις προτιμήσεις της ομάδας προγραμματιστών (ή του προγραμματιστή) που θα το χρησιμοποιήσουν. Η εντολή δημιουργίας του <span class="p-style">.clang‐format</span> είναι η ακόλουθη (π.χ. για το στυλ <span class="p-style">llvm</span>).

```
$ clang‐format ‐‐style=llvm ‐dump‐config > .clang‐format
```

To <span class="p-style">.clang‐format</span> αρχείο αποτελείται από ρυθμίσεις της μορφής κλειδί: τιμή σύμφωνα με το πρότυπο αρχείων <span class="p-style">YAML</span>. Ένα απόσπασμα του αρχείου <span class="p-style">.clang‐format</span>, από τις πάνω από 200 γραμμές, που δημιουργήθηκαν με την παραπάνω εντολή φαίνεται στη συνέχεια:

```
‐‐‐
Language:           Cpp
# BasedOnStyle:     LLVM
...
ColumnLimit:        80
...
IndentWidth:        2
...
PointerAlignment:    Right
...
SpaceBeforeAssignmentOperators: true
...
TabWidth:           8
UseTab:             Never
...
```

Το αρχείο αποτελείται από πολλές ρυθμίσεις. Ανάμεσα σε άλλες ρυθμίσεις ορίζεται ότι το μέγιστο μήκος κάθε γραμμής θα είναι 80 χαρακτήρες, η εσοχή θα είναι 2 χαρακτήρες, οι δηλώσεις δεικτών θα στοιχίζουν το <span class="p-style">\*</span> δεξιά (π.χ. <span class="p-style">int \*p;</span> και όχι για παράδειγμα <span class="p-style">int\* p;</span>), θα υπάρχει κενό αριστερά και δεξιά από τον τελεστή ανάθεσης <span class="p-style">=</span>, το πλάτος κάθε στηλοθέτη θα είναι 8 χαρακτήρες και άλλα.  

Διάφορα IDEs επιτρέπουν την αυτόματη εφαρμογή των κανόνων στυλ που περιέχει το <span class="p-style">.clang‐format</span> με κάποιον συνδυασμό πλήκτρων. Στο VSCode, η επέκταση <span class="p-style">xaverh/vscode‐clang‐format‐provider</span>, εφόσον εγκατασταθεί, ορίζει το συνδυασμό πλήκτρων Alt+Shift+F (ταυτόχρονη πίεση των πλήκτρων Alt, Shift και F) για την εφαρμογή αυτόματης μορφοποίησης. Επίσης, στις ρυθμίσεις (settings) μπορεί να ενεργοποιηθεί η επιλογή “Editor: Format On Save”, που σημαίνει ότι όταν θα αποθηκεύεται ένα αρχείο, αυτόματα θα εφαρμόζεται μορφοποίηση με το clang-format. Η πρόσβαση στις ρυθμίσεις του VSCode γίνεται με τον συνδυασμό πλήκτρων Ctrl+, (ταυτόχρονη πίεση των πλήκτρων Control και κόμμα). Αντίστοιχα, μπορεί να αυτοματοποιηθεί η κλήση του clang-format για vim, emacs, CLion, Visual Studio κ.λπ.  
Αν δεν είναι επιθυμητό να πραγματοποιηθεί εφαρμογή στυλ σε κάποιο τμήμα κώδικα, τότε μπορεί πριν και μετά το τμήμα αυτό να τοποθετηθούν ως σχόλια τα κείμενα <span class="p-style">clang‐format off</span> και <span class="p-style">clang‐format</span> οn αντίστοιχα. Ο κώδικας 18.2 είναι ένα σχετικό παράδειγμα.


```{.c title="Κώδικας 18.2: ch18_p2.c - απενεργοποίηση μορφοποίησης με το clang-format, σε τμήμα του κώδικα." linenums="1"}
--8<-- "src/ch18_p2.c"
```

Περισσότερες πληροφορίες για την εφαρμογή στυλ με το clang-format μπορούν να εντοπιστούν στο [^4].

## 18.4 Άλλα λογισμικά εφαρμογής στυλ σε κώδικα C

Πέρα από το clang-format υπάρχουν και άλλα λογισμικά που μπορούν να χρησιμοποιηθούν για την εφαρμογή κανόνων στυλ σε κώδικα. Ορισμένα από αυτά είναι το GNU Indent, το Uncrustify, το Artistic Style και το clang-tidy.  

Το GNU Indent (<a href="https://www.gnu.org/software/indent/" target="_blank">https://www.gnu.org/software/indent/</a>) είναι ένα εργαλείο του GNU Project και μπορεί να κληθεί από τη γραμμή εντολών (με την εντολή gindent), έτσι ώστε να μορφοποιεί αυτόματα κώδικα τοποθετώντας κατάλληλες εσοχές σύμφωνα με τις οδηγίες στυλ κώδικα του GNU. Υποστηρίζει, όπως και το clang-format, τη ρύθμιση πολλών παραμέτρων και μπορεί να συνδυαστεί με άλλα εργαλεία ανάπτυξης προγραμμάτων.  

Το Uncrustify είναι σύμφωνα με την περιγραφή του που υπάρχει στη σελίδα <a href="https://github.com/uncrustify/uncrustify" target="_blank">https://github.com/uncrustify/uncrustify</a>, ένα εργαλείο ωραιοποίησης (beautifier) κώδικα. Χρησιμοποιεί ένα αρχείο ρυθμίσεων και μέσα σε αυτό καθορίζονται οι επιλογές μορφοποίησης που εφαρμόζει. Υποστηρίζει και άλλες γλώσσες επιπλέον της C όπως η C++, η C#, η Objective‐C και η Java.  

To Artistic Style (<a href="https://astyle.sourceforge.net/" target="_blank">https://astyle.sourceforge.net/</a>) μορφοποιεί κώδικα σε C, C++, Objective‐C, C# και Java ακολουθώντας κανόνες για εσοχές, κενά κ.λπ. Μπορεί να κληθεί από τη γραμμή εντολών, ορίζοντας ρυθμίσεις μορφοποίησης με διακόπτες ή μπορεί να χρησιμοποιεί αρχείο ρυθμίσεων.  

To Clang-Tidy όπως αναφέρθηκε στο Κεφάλαιο 16 είναι ένα λογισμικό στατικής ανάλυσης κώδικα. Ωστόσο, στην κατηγορία ελέγχων αναγνωσιμότητα (readability) περιέχει ελέγχους που σχετίζονται με τη μορφή του κώδικα έτσι ώστε να επιτυγχάνεται καλύτερη αναγνωσιμότητα του κώδικα.

## 18.5 Ιδιώματα C

Τα ιδιώματα C (C idioms) είναι αποσπάσματα κώδικα που ακολουθούν κοινά αποδεκτές συμβάσεις, πρακτικές και οδηγίες στυλ για τη γλώσσα C. Αποτελούν προτεινόμενο και φυσικό τρόπο για να γράφει κανείς κώδικα C ακολουθώντας βέλτιστες πρακτικές. Η έμφαση δίνεται στην αποδοτικότητα και στην αναγνωσιμότητα με συνοπτικό τρόπο. Τα ιδιώματα C έχουν δημιουργηθεί από την κοινότητα των προγραμματιστών C. Η γενική αντίληψη για τα ιδιώματα είναι ότι αξίζει κανείς να τα χρησιμοποιεί για να λύνει τα προβλήματα που επιλύουν, έναντι εναλλακτικών τρόπων.  
Η χρήση των ιδιωμάτων της C υποδηλώνει υψηλή γνώση της γλώσσας, ικανότητα χρήσης των δυνατοτήτων της και κατανόηση καλών πρακτικών. Επιτρέπει σε άλλους προγραμματιστές της C να καταλάβουν γρήγορα τον σκοπό ενός κώδικα, προωθεί την επαναχρησιμοποίηση του κώδικα και διευκολύνει τη συνεργασία και τη διατήρηση κοινών αποθετηρίων κώδικα.  
  
Στη συνέχεια ακολουθούν μερικά παραδείγματα ιδιωμάτων της C.

 1. Αρχικοποίηση ενός αλφαριθμητικού. Η ανάθεση αρχικής τιμής σε ένα αλφαριθμητικό όπως στη συνέχεια, υποδηλώνει ότι δεν επιτρέπεται η αλλαγή του αλφαριθμητικού:
 ```
 const char *message = "Keep Calm!";
 ```
 Η χρήση του <span class="p-style">const</span> απαγορεύει την αλλαγή του περιεχομένου της μεταβλητής <span class="p-style">message</span>.  

 2. Αλφαριθμητικά πολλαπλών γραμμών. Η ενσωμάτωση ενός μεγάλου αλφαριθμητικού στον κώδικα είναι προτιμότερο να γίνεται με το χαρακτηριστικό της αυτόματης συνένωσης διαδοχικών αλφαριθμητικών της C. Για παράδειγμα η ακόλουθη εντολή εμφανίζει ένα κείμενο σε μια γραμμή.
 ```
 printf("C is a razor‐sharp tool, with which "
            "one can create an elegant and efficient program "
            "or a bloody mess. "
            " Brian Kernighan")
 ```

3. Σύγκριση αν δύο αλφαριθμητικά είναι ίσα.
```
if (!strcmp(s1, s2)) {
... // τα λεκτικά s1 και s2 είναι ίσα
}
```
Θα πρέπει να γίνει <span class="p-style">include</span> το <span class="p-style">string.h</span>. Ο κώδικας εκμεταλλεύεται την τιμή επιστροφής 0 της <span class="p-style">strcmp()</span> στην περίπτωση που τα ορίσματά της είναι ίσα αλφαριθμητικά.

4. Εμφάνιση πίνακα αλφαριθμητικών με κόμματα μεταξύ των στοιχείων του πίνακα. Ο κώδικας 18.3 είναι ένα σχετικό παράδειγμα.
```{.c title="Κώδικας 18.3: ch18_p3.c - εμφάνιση στοιχείων πίνακα αλφαριθμητικών, διαχωρισμένων μεταξύ τους με κόμματα." linenums="1"}
--8<-- "src/ch18_p3.c"
```
Η εκτέλεση του κώδικα θα εμφανίσει τα ακόλουθα αποτελέσματα:
```
Dennis Ritchie , Ken Thompson , Brian Kernighan
```

5. Εμφάνιση του τελευταίου στοιχείου ενός πίνακα. Στον κώδικα 18.4 παρουσιάζεται ένα παράδειγμα εμφάνισης του τελευταίου στοιχείου ενός πίνακα ακεραίων.
```{.c title="Κώδικας 18.4: ch18_p4.c - απευθείας μετάβαση στο τελευταίο στοιχείο ενός πίνακα." linenums="1"}
--8<-- "src/ch18_p4.c"
```

6. Διάσχιση των στοιχείων ενός πίνακα. Ο κώδικας 18.5 διασχίζει έναν πίνακα ακεραίων και εμφανίζει τα στοιχεία του.
```{.c title="Κώδικας 18.5: ch18_p5.c - εμφάνιση των στοιχείων ενός πίνακα, χωρίς να χρησιμοποιείται ρητά η τιμή του μεγέθους του πίνακα" linenums="1"}
--8<-- "src/ch18_p5.c"
```
Η εκτέλεση του προγράμματος θα εμφανίσει:
```
8   17  9   42  73  21
```

7. Aνάγνωση χαρακτήρα προς χαρακτήρα της εισόδου μέχρι να εισαχθεί η ειδική τιμή <span class="p-style">EOF</span>. Ο κώδικας 18.6 διαβάζει έναν χαρακτήρα τη φορά και τερματίζει όταν πληκτρολογηθεί Ctrl+D σε Linux και MacOS ή Ctrl+Z στα Windows, που είναι ο τρόπος εισόδου της ειδικής τιμής <span class="p-style">EOF</span>.
```{.c title="Κώδικας 18.6: ch18_p6.c - είσοδος χαρακτήρων από τον χρήστη και τερματισμός μόλις εισαχθεί η ειδική τιμή EOF." linenums="1"}
--8<-- "src/ch18_p6.c"
```
Ένα παράδειγμα εκτέλεσης του κώδικα είναι το ακόλουθο:
```
abc             <‐‐ είσοδος χαρακτήρων από τον χρήστη και enter
abc             <‐‐ έξοδος
def             <‐‐ είσοδος χαρακτήρων από τον χρήστη και enter
def             <‐‐ έξοδος
                <‐‐ εισαγωγή Ctrl+Z (σε Windows) από τον χρήστη
Input ended     <‐‐ μήνυμα πριν τον τερματισμό
```

Μια πηγή εντοπισμού ιδιωματικού κώδικα για τη C αλλά και για διάφορες άλλες γλώσσες προγραμματισμού είναι το <a href="https://programming‐idioms.org/" target="_blank">https://programming‐idioms.org/</a>.


## 18.6 Ασκήσεις

***Άσκηση 1***  
Γράψτε μια συνάρτηση που να δέχεται ως ορίσματα δύο πραγματικούς αριθμούς <span class="p-style">a</span> και <span class="p-style">b</span> και να επιστρέφει έναν τυχαίο πραγματικό αριθμό επιλεγμένο ομοιόμορφα από το διάστημα τιμών <span class="p-style">[a,b)</span>. Καλέστε τη συνάρτηση από το κύριο πρόγραμμα. Μορφοποιήστε το πρόγραμμα χρησιμοποιώντας τις οδηγίες στυλ <span class="p-style">GNU</span> με το clang-format.

***Άσκηση 2***  
Εντοπίστε όλες τις πιθανές επιλογές στυλ που υποστηρίζει το clang-format καλώντας το clang-format από τη γραμμή εντολών με τον διακόπτη <span class="p-style">‐‐help</span>. Μορφοποιήστε έναν κώδικα, με τρεις εμφωλευμένες επαναλήψεις, που να εντοπίζει όλες τις ακέραιες λύσεις της εξίσωσης <span class="p-style">12𝑥−14𝑦+81𝑧 = 100</span> για ακέραιες τιμές των <span class="p-style">𝑥</span>, <span class="p-style">𝑦</span> και <span class="p-style">𝑧</span> στο διάστημα <span class="p-style">[1, 100]</span>, χρησιμοποιώντας όλα τα διαθέσιμα στυλ του clang-format.  
Ποιο ή ποια στυλ δίνουν τον κώδικα με το μικρότερο πλήθος γραμμών;

***Άσκηση 3***  
Δίνεται ο κώδικας 18.7 που εμφανίζει όλους τους ακέραιους αριθμούς από μια ακέραια τιμή <span class="p-style">i1</span>μέχρι μια άλλη ακέραια τιμή <span class="p-style">i2</span>, θεωρώντας ότι οι δύο αυτές τιμές δίνονται ως ορίσματα γραμμής εντολών. Συμπιέστε όσο μπορείτε τον κώδικα από τη γραμμή 10 μέχρι τη γραμμή 33 έτσι ώστε να χρησιμοποιεί τους λιγότερους δυνατούς χαρακτήρες και να διατηρεί την ίδια λειτουργικότητα. Στη συνέχεια, δείτε τις λύσεις που προτάθηκαν για αυτό το πρόβλημα στον διαγωνισμό ShoCC (<a href="https://www.unix‐ag.uni‐kl.de/~conrad/shocc/results.html" target="_blank">https://www.unix‐ag.uni‐kl.de/~conrad/shocc/results.html</a>) το μακρινό 1995.  

```{.c title="Κώδικας 18.7: ch18_e3.c - εκτύπωση όλων των ακέραιων αριθμών ανάμεσα σε δύο ακέραιους αριθμούς (συμπεριλαμβανομένων των τιμών αυτών) που δίνονται ως ορίσματα γραμμής εντολών." linenums="1"}
--8<-- "src/ch18_e3.c"
```

Ακολουθεί ένα παράδειγμα μεταγλώττισης και εκτέλεσης του κώδικα:
```
$ gcc ch18_e3.c ‐o ch18_e3
$ ./ch18_e3 9 5
9 8 7 6 5
```

***Άσκηση 4***  
Μεταβείτε στο <a href="https://programming‐idioms.org/idiom/167/trim‐prefix" target="_blank">https://programming‐idioms.org/idiom/167/trim‐prefix</a>. Χρησιμοποιώντας το ιδίωμα που περιγράφεται εκεί, τροποποιήστε τον κώδικα 18.8 έτσι ώστε να εκτυπώνει κάθε στοιχείο του πίνακα χωρίς το πρόθεμα Mr. ή Ms., εάν αυτό υπάρχει.  

```{.c title="Κώδικας 18.8: ch18_e4.c - εκτύπωση ονομάτων που βρίσκονται σε έναν πίνακα, ζητείται τροποποίηση έτσι ώστε τα προθέματα Mr. και Ms. των ονομάτων να μην εμφανίζονται, εάν υπάρχουν." linenums="1"}
--8<-- "src/ch18_e4.c"
```

[^1]: Glenn Skinner, Suryakanta Shah και Bill Shannon. “C Style and Coding Standards”. Στο: <i>Sun Internal Paper, Token</i> 2151 ().  

[^2]: Jerry Doland και Jon Valett.<i> C style guide.</i> Αδημοσίευτη ερευνητική εργασία. Accessed: 2023-06-01.1994.  

[^3]: L.W. Cannon κ.ά. <i>Recommended C Style and Coding Standards.</i> <a href="http://dmst.aueb.gr/dds/res/cstyle/indexw.htm" target="_blank">http://dmst.aueb.gr/dds/res/cstyle/indexw.htm</a>. Accessed: 2023-06-01.  

[^4]:<i> CLANG-FORMAT STYLE OPTIONS.</i> <a href="https://clang.llvm.org/docs/ClangFormatStyleOptions.html" target="_blank">https://clang.llvm.org/docs/ClangFormatStyleOptions.html</a>. Accessed: 2023-06-01.

