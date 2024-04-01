import tkinter as tk

from tkinter import ttk
from ttkthemes import ThemedTk
#--------------------------------------------------------------------------------------------------------------------------------------

#window = tk.Tk()
window = ThemedTk(theme="adapta")
window.title("PokeMMO Breeding Calculator")
#--------------------------------------------------------------------------------------------------------------------------------------

result_text = tk.StringVar()

#--------------------------------------------------------------------------------------------------------------------------------------

def submit_callback():
    # Function will be called when the "Submit" button is clicked

#--------------------------------------------------------------------------------------------------------------------------------------  
    
    # Initializing
    female_cost   =     int(entry_female.get())
    male_cost     =     int(entry_male.get())
    ivs           =     int(entry_iv.get())
    ball_cost     =     int(entry_ball.get())
    gender_ratio  =     0

    if selected_option.get() == 1:
        gender_ratio = 7000
    elif selected_option.get() == 2:
        gender_ratio = 5000
    elif selected_option.get() == 3:
        gender_ratio = 7000
    elif selected_option.get() == 4:
        gender_ratio = 13000

#--------------------------------------------------------------------------------------------------------------------------------------
        
    # Secondary initializing
    necessary_breeds    = 0
    breeding_bands      = 10000
    female_cost_total   = 0.0
    male_cost_total     = 0.0
    pokemon_needed      = 0
    result              = 0.0
    
#--------------------------------------------------------------------------------------------------------------------------------------    

    # Necessary calculations before calculating result
    for i in range (int(ivs)-1):
        necessary_breeds += (necessary_breeds + 1) 


    breeding_bands = (necessary_breeds*2)*10000
    pokemon_needed = pow(2, int(ivs)-1)
    female_cost_total = (pokemon_needed/2)*female_cost
    male_cost_total = (pokemon_needed/2)*male_cost
    
#--------------------------------------------------------------------------------------------------------------------------------------
    
   #            female         +     male        +              balls           +       bands    +          gender breeding cost   
    result = female_cost_total + male_cost_total + necessary_breeds * ball_cost + breeding_bands + (necessary_breeds/2) * gender_ratio

    result_text.set(str(int(result)))

#--------------------------------------------------------------------------------------------------------------------------------------

# Female entry field
label_female = ttk.Label(window, text="Cost of female")
label_female.grid(row=1, column=0)

entry_female = ttk.Entry(window)
entry_female.grid(row=1, column=1)
entry_female.insert(0, "0")

#--------------------------------------------------------------------------------------------------------------------------------------

# Male entry field
label_male = ttk.Label(window, text="Cost of male")
label_male.grid(row=2, column=0)

entry_male = ttk.Entry(window)
entry_male.grid(row=2, column=1)
entry_male.insert(0, "0")

#--------------------------------------------------------------------------------------------------------------------------------------

# IV entry field
label_iv = ttk.Label(window, text="IVs")
label_iv.grid(row=3, column=0)

entry_iv = ttk.Entry(window)
entry_iv.grid(row=3, column=1)
entry_iv.insert(0, "5")

#--------------------------------------------------------------------------------------------------------------------------------------

# Ball cost entry field
label_ball = ttk.Label(window, text="Ball cost")
label_ball.grid(row=4, column=0)

entry_ball = ttk.Entry(window)
entry_ball.grid(row=4, column=1)
entry_ball.insert(0, "200")

#--------------------------------------------------------------------------------------------------------------------------------------

# Gender ratio
label_options = ttk.Label(window, text="Female / Male ratio")
label_options.grid(row=0, column=3)

#--------------------------------------------------------------------------------------------------------------------------------------

# Variable to store the selected option
selected_option = tk.IntVar(value="2")

# Creating Radiobuttons
ttk.Radiobutton(window, text="75% / 25%", variable=selected_option, value="1").grid(row=1, column=3)
ttk.Radiobutton(window, text="50% / 50%", variable=selected_option, value="2").grid(row=2, column=3)
ttk.Radiobutton(window, text="25% / 75%", variable=selected_option, value="3").grid(row=3, column=3)
ttk.Radiobutton(window, text="12.5% / 87.5%", variable=selected_option, value="4").grid(row=4, column=3)


#--------------------------------------------------------------------------------------------------------------------------------------

# Submit button
submit_button = ttk.Button(window, text="Submit", command=submit_callback)
submit_button.grid(row=8, column=1, columnspan=2)

#--------------------------------------------------------------------------------------------------------------------------------------

# Result
result_title_label = ttk.Label(window, text="Result:", font=("Helvetica", 12))
result_title_label.grid(row=9, column=0)

result_label = ttk.Label(window, textvariable=result_text, font=("Helvetica", 12))
result_label.grid(row=9, column=1)

#--------------------------------------------------------------------------------------------------------------------------------------

window.mainloop()



#  entry1.delete(0,tk.END)
