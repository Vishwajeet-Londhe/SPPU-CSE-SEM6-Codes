def triage_system():
    print("=== Hospital Expert System: Patient Triage Assistant ===")

    name = input("Enter Patient Name: ")
    age = int(input("Enter Age: "))
    print("\nSelect Symptoms (Y/N):")
    
    chest_pain = input("Chest Pain? ").lower() == 'y'
    short_breath = input("Shortness of Breath? ").lower() == 'y'
    bleeding = input("Heavy Bleeding? ").lower() == 'y'
    high_fever = input("High Fever? ").lower() == 'y'
    injury = input("Recent Injury? ").lower() == 'y'
    dizziness = input("Dizziness or Fainting? ").lower() == 'y'
    stomach_pain = input("Severe Stomach Pain? ").lower() == 'y'

    print("\nAnalyzing symptoms...")

    if bleeding or injury:
        department = "Emergency Room (ER)"
        advice = "Immediate attention required. Proceed to the ER."
    elif chest_pain or short_breath:
        department = "Cardiology"
        advice = "Cardiac symptoms detected. Visit Cardiology immediately."
    elif high_fever and age < 12:
        department = "Pediatrics"
        advice = "High fever in child. Visit Pediatrics urgently."
    elif high_fever:
        department = "General Medicine"
        advice = "Consult a general physician for evaluation."
    elif dizziness:
        department = "Neurology"
        advice = "Neurological symptoms present. Visit Neurology."
    elif stomach_pain:
        department = "Gastroenterology"
        advice = "Visit a gastroenterologist for further diagnosis."
    else:
        department = "Outpatient (OPD)"
        advice = "No critical symptoms. You may proceed to OPD."

    print(f"\n=== Patient Report ===")
    print(f"Name: {name}")
    print(f"Recommended Department: {department}")
    print(f"Advice: {advice}")


if __name__ == "__main__":
    triage_system()
