#include <ntddk.h>
#include <dispmprt.h>

typedef struct
{
	PDEVICE_OBJECT pNextDeviceObject;
}DEVICE_EXTENSION, *PDEVICE_EXTENSION;

DRIVER_INITIALIZATION_DATA Primary_Structure_Address = { 0, };

DXGKDDI_ADD_DEVICE						extension_AddDevice;

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath)
{
	DRIVER_INITIALIZATION_DATA* DriverInitializationData = { '\0', };

	Primary_Structure_Address = *DriverInitializationData;

	if (!ARGUMENT_PRESENT(DriverObject) || !ARGUMENT_PRESENT(RegistryPath)) {
		return STATUS_INVALID_PARAMETER;
	}

	DriverInitializationData->Version = DXGKDDI_INTERFACE_VERSION_WIN7;
	DriverInitializationData->DxgkDdiAddDevice = extension_AddDevice;

	return DxgkInitialize(DriverObject, RegistryPath, DriverInitializationData);
}

NTSTATUS extension_AddDevice(IN const PDEVICE_OBJECT PhysicalDeviceObject, OUT PVOID *MiniportDeviceContext)
{
	NTSTATUS(*ptrFunction)(IN_CONST_PDEVICE_OBJECT PhysicalDeviceObject, OUT PVOID);
	DbgPrint("LOFILTER: AddDevice called\n");
	memcpy(&ptrFunction, &Primary_Structure_Address.DxgkDdiAddDevice, 4);
	NTSTATUS Status = (*ptrFunction)(PhysicalDeviceObject, MiniportDeviceContext);
	return Status;
}