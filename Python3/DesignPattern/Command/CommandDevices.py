from abc import ABC, abstractmethod


# -----------------------------
# 1. Interface Command
# -----------------------------
class Command(ABC):
    @abstractmethod
    def execute(self):
        pass

    @abstractmethod
    def undo(self):
        pass


# -----------------------------
# 2. Les "Receivers" : les appareils
# -----------------------------
class Light:
    def on(self):
        print("La lumière est allumée")

    def off(self):
        print("La lumière est éteinte")


class Fan:
    def start(self):
        print("Le ventilateur tourne")

    def stop(self):
        print("Le ventilateur s'arrête")


# -----------------------------
# 3. Les commandes concrètes
# -----------------------------
class LightOnCommand(Command):
    def __init__(self, light: Light):
        self.light = light

    def execute(self):
        self.light.on()

    def undo(self):
        self.light.off()


class LightOffCommand(Command):
    def __init__(self, light: Light):
        self.light = light

    def execute(self):
        self.light.off()

    def undo(self):
        self.light.on()


class FanStartCommand(Command):
    def __init__(self, fan: Fan):
        self.fan = fan

    def execute(self):
        self.fan.start()

    def undo(self):
        self.fan.stop()


class FanStopCommand(Command):
    def __init__(self, fan: Fan):
        self.fan = fan

    def execute(self):
        self.fan.stop()

    def undo(self):
        self.fan.start()


# -----------------------------
# 4. L'Invoker : la télécommande
# -----------------------------
class RemoteControl:
    def __init__(self):
        self.command_on = None
        self.command_off = None
        self.history = []  # Pour undo

    def set_command(self, command_on: Command, command_off: Command):
        self.command_on = command_on
        self.command_off = command_off

    def press_on(self):
        print("Bouton ON pressé")
        self.command_on.execute()
        self.history.append(self.command_on)

    def press_off(self):
        print("Bouton OFF pressé")
        self.command_off.execute()
        self.history.append(self.command_off)

    def press_undo(self):
        if self.history:
            command = self.history.pop()
            print("Undo command")
            command.undo()
        else:
            print("Rien à annuler")


# -----------------------------
# 5. Utilisation
# -----------------------------
if __name__ == "__main__":
    # Appareils
    light = Light()
    fan = Fan()

    # Commandes
    light_on = LightOnCommand(light)
    light_off = LightOffCommand(light)
    fan_start = FanStartCommand(fan)
    fan_stop = FanStopCommand(fan)

    # Télécommande
    remote = RemoteControl()

    # Contrôle de la lumière
    remote.set_command(light_on, light_off)
    remote.press_on()  # La lumière est allumée
    remote.press_off()  # La lumière est éteinte
    remote.press_undo()  # Undo -> La lumière est rallumée

    # Contrôle du ventilateur
    remote.set_command(fan_start, fan_stop)
    remote.press_on()  # Le ventilateur tourne
    remote.press_off()  # Le ventilateur s'arrête
    remote.press_undo()  # Undo -> Le ventilateur tourne
