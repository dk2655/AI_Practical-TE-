def hypothesize():
    animal = classify_animal()
    print("I guess that the animal is:", animal)

def classify_animal():
    if mammal():
        if carnivore():
            if has_tawny_color() and has_dark_spots():
                return "cheetah"
            elif has_tawny_color() and has_black_stripes():
                return "tiger"
        elif ungulate():
            if has_long_neck() and has_long_legs():
                return "giraffe"
            elif has_black_stripes():
                return "zebra"
    elif bird():
        if does_not_fly():
            if has_long_neck():
                return "ostrich"
            elif swims() and is_black_and_white():
                return "penguin"
            elif appears_in_story_Ancient_Mariner() and flys_well():
                return "albatross"
    return "unknown"

def verify(attribute):
    response = input(f"Does the animal have {attribute}? (yes/no): ").lower()
    return response == "yes"

def mammal():
    return verify("hair") or verify("gives milk")

def bird():
    return verify("feathers") or (verify("flys") and verify("lays eggs"))

def carnivore():
    return verify("eats meat") or (verify("has pointed teeth") and verify("has claws") and verify("has forward eyes"))

def ungulate():
    return (mammal() and verify("hooves")) or (mammal() and verify("chews cud"))

def has_tawny_color():
    return verify("tawny color")

def has_dark_spots():
    return verify("dark spots")

def has_black_stripes():
    return verify("black stripes")

def has_long_neck():
    return verify("long neck")

def has_long_legs():
    return verify("long legs")

def does_not_fly():
    return not verify("flies")

def swims():
    return verify("swims")

def is_black_and_white():
    return verify("black and white")

def appears_in_story_Ancient_Mariner():
    return verify("appears in story Ancient Mariner")

def flys_well():
    return verify("flys well")

def main():
    hypothesize()

if __name__ == "__main__":
    main()
