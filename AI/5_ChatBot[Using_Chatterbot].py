# Install Cython by using: pip install cython
# Only then install chatterbot using: pip install chatterbot 

from chatterbot import ChatBot

# Inorder to train our bot, we have to import a trainer package
# "ChatterBotCorpusTrainer"
from chatterbot.trainers import ChatterBotCorpusTrainer

# Give a name to the chatbot “corona bot”
# and assign a trainer component.
chatbot=ChatBot('corona bot')

# Create a new trainer for the chatbot
trainer = ChatterBotCorpusTrainer(chatbot)

# Now let us train our bot with multiple corpus
trainer.train("chatterbot.corpus.english.greetings","chatterbot.corpus.english.conversations" )


question = input("Ask me anything:(Enter Endgame to exit) ")
while question != "Endgame" or question != "endgame":
        response = chatbot.get_response(question)
        print(response)
        question = input("Enter your question:(Enter Endgame to exit) ")
print("Goodbye")
