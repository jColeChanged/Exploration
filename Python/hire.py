# Is this interesting? Takes words used in past hire, no hire decisions and uses
# it to order canidates according to their chance of getting hired. Makes use of
# the baysiean filtering algorithm mentioned on Paul Graham's blog
#
# Note: I haven't taken any machine learning courses and had no experience with
# baysiean filtering prior to 4/26/2011. So I might not be using the right
# algorithm for the job. Also, a lot of information that could be used isn't
# being used. Case in point, checkboxes aren't factored in. The goal here was
# to share the idea while also getting you interested in me as an intern.

from operator import mul
def product(col):
    return reduce(mul, col, 1) if col else 0
            
# {"word": (P(Hire|word), used_in_hire, used)}
# BAYES_DICT = {"Joshua": (1.0, 1, 1),
#               "Cole": (1.0, 1, 1)}
# ^ ... hopefully ;)
BAYES_DICT = {}

def update_probabilities(bayes_dict, applicant, hire):
    """Changes bayes_dict to reflect hiring decisions. Call only once
    per applicant.

    For the sake of simplicity I'm assuming the words were
    already cleaned up and put into list form.

    If your familiar with bayseian filtering I'd love feedback on the code.
    I wrote this quickly and have never used bayseian filtering before now.

    Args:
      bayes_dict: dict {word: (P(word|hire), used_in_hires, used)}
      applicant: the applicant to update the probabilities with
      hire: bool, whether or not the applicant was hired.
      
    Returns:
      Doesn't return anything, but does modify bayes_dict.
    """
    for word in applicant.words_used:
        word_frequencies = bayes_dict.get(word, (0.0, 0, 0))
        used_in_hires  = word_frequencies[1] + 1 if hire else word_frequencies[1]
        used = word_frequencies[2] + 1
        chance_of_hire = float(used_in_hires)/ used
        bayes_dict[word] = (chance_of_hire, used_in_hires, used)

class Applicant:
    def __init__(self, name, email, words_used, bayes_dict):
        self.name = name
        self.email = email
        self.words_used = words_used
        self.set_chance_of_hiring(bayes_dict)

    def set_chance_of_hiring(self, bayes_dict):
        # Niave baysiean classification
        probabilities = []
        for word in self.words_used:
            try:
                probabilities.append(bayes_dict[word][0])
            except KeyError:
                print "Word", word, "hasn't been seen before. Skipping."
        prod = product(probabilities)
        other_part = product(map(lambda x: 1-x, probabilities))
        try:
            self.chance_of_hiring = prod / (prod + other_part)
        except ZeroDivisionError:
            self.chance_of_hiring = 0.0

# In one of Paul Graham's essays on the subject he says that a message  of
# "sex", "sexy" would produce a chance of 99.67& given sex having 97% and
# sexy having 99% chhance of being spam. So as a simple test case:
# BAYES_DICT = {"sex": (.97, 97, 100),
#               "sexy": (.99, 99, 100)}
#
test_applicant = Applicant("test", "test@test.com", ["sex", "sexy"], BAYES_DICT)
# print test_applicant.chance_of_hiring
# ::> 0.999687695191
#
# So apparently it works on at least this case.
