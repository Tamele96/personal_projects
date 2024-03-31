import tkinter as tk

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
    
   #              female       +     male        +              balls           +       bands    +                gender breeding cost   
    result = female_cost_total + male_cost_total + necessary_breeds * ball_cost + breeding_bands + (necessary_breeds/2) * gender_ratio

    print(int(result))


#--------------------------------------------------------------------------------------------------------------------------------------

window = tk.Tk()

#--------------------------------------------------------------------------------------------------------------------------------------

# Female entry field
label_female = tk.Label(text="Cost of female")
label_female.pack()

entry_female = tk.Entry()
entry_female.pack()
entry_female.insert(0, "0")

#--------------------------------------------------------------------------------------------------------------------------------------

# Male entry field
label_male = tk.Label(text="Cost of male")
label_male.pack()

entry_male = tk.Entry()
entry_male.pack()
entry_male.insert(0, "0")

#--------------------------------------------------------------------------------------------------------------------------------------

# IV entry field
label_iv = tk.Label(text="IVs")
label_iv.pack()

entry_iv = tk.Entry()
entry_iv.pack()
entry_iv.insert(0, "5")

#--------------------------------------------------------------------------------------------------------------------------------------

# Gender ratio
label_options = tk.Label(text="Female ratio")
label_options.pack()

# Variable to store the selected option
selected_option = tk.IntVar(value="2")

# Creating Radiobuttons
tk.Radiobutton(window, text="75%", variable=selected_option, value="1").pack()
tk.Radiobutton(window, text="50%", variable=selected_option, value="2").pack()
tk.Radiobutton(window, text="25%", variable=selected_option, value="3").pack()
tk.Radiobutton(window, text="12.5%", variable=selected_option, value="4").pack()


#--------------------------------------------------------------------------------------------------------------------------------------

# Ball cost entry field
label_ball = tk.Label(text="Ball cost")
label_ball.pack()

entry_ball = tk.Entry()
entry_ball.pack()
entry_ball.insert(0, "200")

#--------------------------------------------------------------------------------------------------------------------------------------

# Submit button
submit_button = tk.Button(window, text="Submit", command=submit_callback)
submit_button.pack()

#--------------------------------------------------------------------------------------------------------------------------------------

# Result
result_label = tk.Label(text="Result: ", font=("Helvetica", 12))
result_label.pack()



#--------------------------------------------------------------------------------------------------------------------------------------

window.mainloop()





      #  entry1.insert(0, "Python")

      #  entry1.delete(0,tk.END)
