Breeding Calculator by Tameletwo

_______________________________________________________________________________________

This Python program uses Tkinter with ttkbootstrap to build a window application for
the PokeMMO breeding calculator I built.

Icons were chosen from https://www.flaticon.com and created by "Roundicons Freebies"

_______________________________________________________________________________________

If you don't feel comfortable to download a stranger's .exe file, feel free to copy
the code and use it for yourself. You will find it on GitHub under:
https://github.com/Tamele96/personal_projects/tree/main/Window%20Applications/Python%20(Tkinter)/breeding_calculator

To run the code you will need to have or download Python, as well as the
Tkinter and ttkbootstrap module.


NOTE:
In case you do so and want to include the Pikachu icon in your window, you have to
specify your path where your Pikachu icon is in. Alternatively delete that line to 
remove the icon. More info within the code's comments.

_______________________________________________________________________________________

IMPORTANT NOTE:

The breeding calculator is giving you a rough estimate, or rather an upper bound of how
much it can cost. With 3 IVs or higher you should almost always manage to get the
desired Pokemon for cheaper through more strategic breeding.
For more information find some guides on breeding on the internet before you commit
to a high cost breeding process.
_______________________________________________________________________________________

HOW TO USE:

Enter values in the input fields to get an estimated cost of the process.

---

Female field:
Enter the estimated average of how much you will have to pay for the female part of
your breeding process (Average of females with 1 wanted IV cost)

---

Male field:
Enter the estimated average of how much you will have to pay for the male part of
your breeding process (Average of males with 1 wanted IV cost)

---

IV field:
Enter how many IVs you want to breed on your Pokemon.
(Value between 2 and 6)

---

Ball cost field:
Just in case you want to use a different ball for your Pokemon, or if you want to exclude
the cost for Pokeballs for your calculation, enter how much you pay for each ball to put
the Pokemon for each breeding step in.

---

Gender ratio:
The radio buttons let you choose the gender ratio of the Pokemon, as the cost will vary,
depending on the odds of encountering/breeding a male or female.

For more information check out the following links:
https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_gender_ratio
https://forums.pokemmo.com/index.php?/topic/49440-the-breeding-guide/ (information at 9.)

---

The submit button will update your result, unless an ivalid input was given
in any field. In that case the field's value will be reset and an error
message will appear notifying you of what went wrong.
