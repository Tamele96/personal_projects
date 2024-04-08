import ttkbootstrap as ttk
from ttkbootstrap.constants import *
from PIL import Image, ImageTk

#--------------------------------------------------------------------------------------------------------------

root = ttk.Window(themename="darkly")
root.title("PokeMMO Breeding Calculator")
root.resizable(False, False)

# Defining result output
result_text = ttk.StringVar()

#--------------------------------------------------------------------------------------------------------------

def submit_callback():

    # Clear error message
    error_label.pack_forget()

    # Text input fields

    # female
    female_cost_str = entry_female.get()
    if female_cost_str.startswith("-"):
        female_cost = 0
        entry_female.delete(0, ttk.END)
        entry_female.insert(0, "0")
        # Display error message for female cost
        error_label.config(text="Error! Please enter a valid positive number for female cost!\nYour female cost was set to 0.")
        error_label.pack()
        return
    elif not female_cost_str.isdigit():
        entry_female.delete(0, ttk.END)
        entry_female.insert(0, "0")
        female_cost = 0
        # Display error message for female cost
        error_label.config(text="Error! Please enter a valid number for female cost!\nYour female cost was set to 0.")
        error_label.pack()
        return
    else:
        female_cost = int(female_cost_str)
    
    #--------------------------------------------------------------------------------------------------------------
    
    # male
    male_cost_str = entry_male.get()
    if male_cost_str.startswith("-"):
        male_cost = 0
        entry_male.delete(0, ttk.END)
        entry_male.insert(0, "0")
        # Display error message for male cost
        error_label.config(text="Error! Please enter a valid positive number for male cost!\nYour male cost was set to 0.")
        error_label.pack()
        return
    elif not male_cost_str.isdigit():
        entry_male.delete(0, ttk.END)
        entry_male.insert(0, "0")
        male_cost = 0
        # Display error message for male cost
        error_label.config(text="Error! Please enter a valid number for male cost!\nYour male cost was set to 0.")
        error_label.pack()
        return
    else:
        male_cost = int(male_cost_str)
    
    #--------------------------------------------------------------------------------------------------------------

    # ivs
    ivs_str = entry_iv.get()
    if not ivs_str.isdigit():
        entry_iv.delete(0, ttk.END)
        entry_iv.insert(0, "2")
        ivs = 2
        # Display error message for ivs
        error_label.config(text="Error! Please enter a valid number for IVs!\nYour IVs field was set to 2.")
        error_label.pack()
        return
    else:
        ivs = int(ivs_str)        
    if ivs < 2 or ivs > 6:
        ivs = 2
        entry_iv.delete(0, ttk.END)
        entry_iv.insert(0, "2")
        # Display error message for ivs
        error_label.config(text="Error! IVs must be between 2 and 6!\nYour IVs field was set to 2.")
        error_label.pack()
        return

#--------------------------------------------------------------------------------------------------------------
    
   # ball cost
    ball_cost_str = entry_ball.get()
    if ball_cost_str.startswith("-"):
        ball_cost = 200
        entry_ball.delete(0, ttk.END)
        entry_ball.insert(0, "200")  
        # Display error message for ball cost
        error_label.config(text="Error! Please enter a valid positive number for Ball cost!\nYour Ball cost was set to 200.")
        error_label.pack()
        return
    elif not ball_cost_str.isdigit():
        entry_ball.delete(0, ttk.END)
        entry_ball.insert(0, "200")
        ball_cost = 200
        # Display error message for ball cost
        error_label.config(text="Error! Please enter a valid number for Ball cost!\nYour Ball cost was set to 200.")
        error_label.pack()
        return
    else:
        ball_cost = int(ball_cost_str)
#--------------------------------------------------------------------------------------------------------------
        
    # Radio buttons

    gender_ratio = 0

    # Formula under the assumption that you have to pick male and female an equal amount of times:
    # (((upper_bound-lowerbound)/100)*ratio_percentage)+lower_bound
    # Therefore the average price to pick gender will be:

    if selected_option.get() == 1:
        gender_ratio = 8000
    elif selected_option.get() == 2:
        gender_ratio = 5000
    elif selected_option.get() == 3:
        gender_ratio = 8000
    elif selected_option.get() == 4:
        gender_ratio = 19000

#--------------------------------------------------------------------------------------------------------------
                
    # Initialization
    necessary_breeds = 0
    breeding_bands = 10000
    female_cost_total = 0.0
    male_cost_total = 0.0
    pokemon_needed = 0
    result = 0.0

    for i in range(int(ivs) - 1):
        necessary_breeds += (necessary_breeds + 1)

    breeding_bands = (necessary_breeds * 2) * 10000
    pokemon_needed = pow(2, int(ivs) - 1)
    female_cost_total = (pokemon_needed / 2) * female_cost
    male_cost_total = (pokemon_needed / 2) * male_cost

    result = female_cost_total + male_cost_total + necessary_breeds * ball_cost + breeding_bands + (
                necessary_breeds / 2) * gender_ratio

    result_text.set("{:,}".format(int(result)))

#--------------------------------------------------------------------------------------------------------------
#--------------------------------------------------------------------------------------------------------------
#--------------------------------------------------------------------------------------------------------------

# Frames:
    
# Frame left    
frame_left = ttk.Frame(root)
frame_left.grid(row=0, column=0, padx=10, pady=10, sticky="nsew")

# Frame right
frame_right = ttk.Frame(root)
frame_right.grid(row=0, column=1, padx=10, pady=10, sticky="nsew")

# Frame for error message
frame_error = ttk.Frame(root)
frame_error.grid(row=1, column=0, columnspan=2, padx=10, pady=10, sticky="nsew")

# Frame bottom
frame_bottom = ttk.Frame(root)
frame_bottom.grid(row=2, column=0, columnspan=2, padx=10, pady=10, sticky="nsew")

#--------------------------------------------------------------------------------------------------------------

# Labels in left frame

# Input label
label_input = ttk.Label(frame_left, text="Enter your data:")
label_input.grid(row=0, column=1, columnspan=2, padx=5, pady=(10, 5))

#--------------------------------------------------------------------------------------------------------------

# Female label
label_female = ttk.Label(frame_left, text="Cost of female:")
label_female.grid(row=1, column=0, padx=(10, 8), pady=5, sticky="e")

# Female entry field
entry_female = ttk.Entry(frame_left)
entry_female.grid(row=1, column=1, padx=(0, 10), pady=5)
entry_female.insert(0, "0")

#--------------------------------------------------------------------------------------------------------------

# Male label
label_male = ttk.Label(frame_left, text="Cost of male:")
label_male.grid(row=2, column=0, padx=(10, 8), pady=5, sticky="e")

# Male entry field
entry_male = ttk.Entry(frame_left)
entry_male.grid(row=2, column=1, padx=(0, 10), pady=5)
entry_male.insert(0, "0")

#--------------------------------------------------------------------------------------------------------------

# IV label
label_iv = ttk.Label(frame_left, text="IVs:", justify=CENTER)
label_iv.grid(row=3, column=0, padx=(10, 40), pady=5, sticky="e")

# IV entry field
entry_iv = ttk.Entry(frame_left)
entry_iv.grid(row=3, column=1, padx=(0, 10), pady=5)
entry_iv.insert(0, "5")

#--------------------------------------------------------------------------------------------------------------

# Ball cost label
label_ball = ttk.Label(frame_left, text="Ball cost:")
label_ball.grid(row=4, column=0, padx=(10, 20), pady=5, sticky="e")

# Ball cost entry field
entry_ball = ttk.Entry(frame_left)
entry_ball.grid(row=4, column=1, padx=(0, 10), pady=5)
entry_ball.insert(0, "200")

#--------------------------------------------------------------------------------------------------------------

# Gender ratio label
label_options = ttk.Label(frame_right, text="Female / Male ratio:")
label_options.pack(side="top", padx=30, pady=10)
selected_option = ttk.IntVar(value="2")

# Radio buttons vertically centered
ttk.Radiobutton(frame_right, text="75% / 25%", variable=selected_option, value="1").pack(anchor="w", padx=30, pady=11)
ttk.Radiobutton(frame_right, text="50% / 50%", variable=selected_option, value="2").pack(anchor="w", padx=30, pady=11)
ttk.Radiobutton(frame_right, text="25% / 75%", variable=selected_option, value="3").pack(anchor="w", padx=30, pady=11)
ttk.Radiobutton(frame_right, text="12.5% / 87.5%", variable=selected_option, value="4").pack(anchor="w", padx=30, pady=11)

#--------------------------------------------------------------------------------------------------------------

# Submit button
submit_button = ttk.Button(frame_bottom, text="Submit", command=submit_callback, bootstyle=(SUCCESS, OUTLINE), width=20)
submit_button.pack(pady=10)

#--------------------------------------------------------------------------------------------------------------

# Result labels
result_title_label = ttk.Label(frame_bottom, text="Total cost to breed:", font=("Helvetica", 12))
result_title_label.pack(side="left", padx=5, pady=50)

result_label = ttk.Label(frame_bottom, textvariable=result_text, font=("Helvetica", 12))
result_label.pack(side="left", padx=5, pady=5)

#--------------------------------------------------------------------------------------------------------------

# Error message label
error_label = ttk.Label(frame_error, text="", foreground="red")
error_label.pack()
error_label.grid(row=0, column=0, padx=5, pady=5)

#--------------------------------------------------------------------------------------------------------------

root.mainloop()