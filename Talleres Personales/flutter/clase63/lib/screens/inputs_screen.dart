import 'package:clase63/widgets/widgets.dart';
import 'package:flutter/material.dart';

class InputsScreen extends StatelessWidget {
  const InputsScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final GlobalKey<FormState> myFormKey = GlobalKey<FormState>();

    final Map<String, String> formValues = {
      'email': 'ivanrene10@gmail.com',
      'password': '12345Aa',
      'firstName': 'Ivan Rene',
      'lastName': 'Ramirez Castro',
      'role': 'admin',
    };
    return Scaffold(
      appBar: AppBar(
        title: const Text('Inputs y Forms'),
      ),
      body: SingleChildScrollView(
        child: Padding(
          padding: const EdgeInsets.symmetric(vertical: 30, horizontal: 20),
          child: Form(
            key: myFormKey,
            child: Column(
              children: [
                CustonInputField(
                  labelText: 'Nombre',
                  hintText: 'Nombre del usuario',
                  formProperty: 'firstName',
                  formValues: formValues,
                ),
                const SizedBox(height: 30),
                CustonInputField(
                  labelText: 'Apellido',
                  hintText: 'Apellido del usuario',
                  formProperty: 'lastName',
                  formValues: formValues,
                ),
                const SizedBox(height: 30),
                CustonInputField(
                  labelText: 'Correo',
                  hintText: 'Correo del usuario',
                  keyboardType: TextInputType.emailAddress,
                  suffixIcon: Icons.email,
                  validator: 'email',
                  formProperty: 'email',
                  formValues: formValues,
                ),
                const SizedBox(height: 30),
                CustonInputField(
                  labelText: 'Contraseña',
                  hintText: 'Contraseña del usuario',
                  isPassword: true,
                  suffixIcon: Icons.lock,
                  minCharacters: 6,
                  maxCharacters: 10,
                  validator: 'password',
                  formProperty: 'password',
                  formValues: formValues,
                ),
                const SizedBox(height: 30),
                DropdownButtonFormField<String>(
                  items: const [
                    DropdownMenuItem(
                      child: Text('Admin'),
                      value: 'admin',
                    ),
                    DropdownMenuItem(
                      child: Text('User'),
                      value: 'user',
                    ),
                    DropdownMenuItem(
                      child: Text('Guest'),
                      value: 'guest',
                    ),
                  ],
                  value: formValues['role'],
                  onChanged: (value) {
                    formValues['role'] = value ?? 'User';
                  },
                ),
                const SizedBox(height: 30),
                SizedBox(
                    width: double.infinity,
                    child: ElevatedButton(
                        onPressed: () {
                          FocusScope.of(context).requestFocus(FocusNode());
                          if (!myFormKey.currentState!.validate()) {
                            debugPrint('Formulario no válido');
                            return;
                          }
                          // * imprimir datos en consola
                          debugPrint(formValues.toString());
                        },
                        child: const Text('Enviar'))),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
