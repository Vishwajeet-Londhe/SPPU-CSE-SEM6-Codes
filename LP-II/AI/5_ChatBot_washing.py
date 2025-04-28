import re

def chatbot_response(user_input):
    user_input = user_input.lower().strip()

    responses = {
        r"\b(1|hello|hi|hey)\b": "Hello! Welcome to the IFB Washing Machine Service Centre. How can I assist you today?",
        r"\b(2|how are you)\b": "I'm doing great! I'm here to help you with your IFB washing machine service needs.",
        r"\b(3|book service|schedule service|repair)\b": "Sure! Please provide your washing machine model number and preferred service date.",
        r"\b(4|installation)\b": "We provide installation support. Please share your product details and address.",
        r"\b(5|warranty status|check warranty)\b": "Please provide your machine's serial number to check warranty status.",
        r"\b(6|troubleshooting|problem|issue)\b": "I'm here to help! Please describe the problem you are facing with your washing machine.",
        r"\b(7|service charges|cost)\b": "Service charges vary based on the issue. Basic inspection charges are ₹300.",
        r"\b(8|parts replacement|spare parts)\b": "We use genuine IFB spare parts. Charges depend on the part that needs replacement.",
        r"\b(9|service status|track request)\b": "Please share your service request number to track the status.",
        r"\b(10|customer care|support number)\b": "You can reach our customer care at 1800-3000-5678 (toll-free).",
        r"\b(11|working hours|timings)\b": "Our service center is open from 9 AM to 7 PM, Monday to Saturday.",
        r"\b(12|location|address)\b": "We are located at XYZ Plaza, Main Road, YourCity.",
        r"\b(13|feedback|complaint)\b": "We're sorry for the inconvenience. Please share your feedback or complaint, and we'll address it quickly.",
        r"\b(14|maintenance tips|care tips)\b": "Always use IFB-approved detergents, avoid overloading, and clean the filter regularly for best performance.",
        r"\b(15|bye|exit)\b": "Goodbye! Thank you for contacting IFB Service Centre. 😊"
    }

    for pattern, response in responses.items():
        if re.search(pattern, user_input):
            return response

    return "I'm sorry, I didn't understand that. Could you please rephrase or ask about IFB washing machine service?"

# Chatbot interaction loop
print("Welcome to the IFB Washing Machine Service Centre Chatbot! Type 'exit' to end the conversation.")

while True:
    user_message = input("You: ")
    if user_message.lower() in ["bye", "exit"]:
        print("Chatbot: Goodbye! Thank you for contacting IFB Service Centre. 😊")
        break
    response = chatbot_response(user_message)
    print("Chatbot:", response)