#include <ntddk.h>
#include <dispmprt.h>

typedef struct
{
	PDEVICE_OBJECT pNextDeviceObject;
}DEVICE_EXTENSION, *PDEVICE_EXTENSION;

DXGKDDI_ADD_DEVICE						extension_AddDevice;
DXGKDDI_START_DEVICE					extension_StartDevice;
DXGKDDI_STOP_DEVICE						extension_StopDevice;
DXGKDDI_REMOVE_DEVICE					extension_RemoveDevice;
DXGKDDI_QUERYADAPTERINFO				extension_D3DDDIQueryAdapterInfo;
DXGKDDI_QUERY_CHILD_RELATIONS			extension_QueryChildRelations;
DXGKDDI_QUERY_CHILD_STATUS				extension_QueryChildStatus;
DXGKDDI_QUERY_DEVICE_DESCRIPTOR			extension_QueryDeviceDescriptor;
DXGKDDI_ENUMVIDPNCOFUNCMODALITY         extension_D3DDDIEnumVidPnCofuncModality;



NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath)
{
	DRIVER_INITIALIZATION_DATA DriverInitializationData = { '\0', };

	if (!ARGUMENT_PRESENT(DriverObject) || !ARGUMENT_PRESENT(RegistryPath)) {
		return STATUS_INVALID_PARAMETER;
	}

	DriverInitializationData.Version = DXGKDDI_INTERFACE_VERSION_WIN7;
	DriverInitializationData.DxgkDdiAddDevice = extension_AddDevice;
	DriverInitializationData.DxgkDdiStartDevice = extension_StartDevice;
	DriverInitializationData.DxgkDdiStopDevice = extension_StopDevice;
	DriverInitializationData.DxgkDdiRemoveDevice = extension_RemoveDevice;
	DriverInitializationData.DxgkDdiQueryAdapterInfo = extension_D3DDDIQueryAdapterInfo;
	DriverInitializationData.DxgkDdiQueryChildRelations = extension_QueryChildRelations;
	DriverInitializationData.DxgkDdiQueryChildStatus = extension_QueryChildStatus;
	DriverInitializationData.DxgkDdiQueryDeviceDescriptor = extension_QueryDeviceDescriptor;
	DriverInitializationData.DxgkDdiEnumVidPnCofuncModality = extension_D3DDDIEnumVidPnCofuncModality;

	return DxgkInitialize(DriverObject, RegistryPath, &DriverInitializationData);
}

NTSTATUS extension_AddDevice(IN const PDEVICE_OBJECT PhysicalDeviceObject, OUT PVOID *MiniportDeviceContext)
{
	DbgPrint("DRIVER: AddDevice called\n");
	UNREFERENCED_PARAMETER(PhysicalDeviceObject);
	UNREFERENCED_PARAMETER(MiniportDeviceContext);

	return STATUS_SUCCESS;
}

NTSTATUS extension_StartDevice(IN const PVOID MiniportDeviceContext, IN PDXGK_START_INFO DxgkStartInfo, IN PDXGKRNL_INTERFACE DxgkInterface, OUT PULONG NumberOfVideoPresentSources, OUT PULONG NumberOfChildren)
{
	DbgPrint("DRIVER: StartDevice called\n");
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(DxgkStartInfo);
	UNREFERENCED_PARAMETER(DxgkInterface);
	UNREFERENCED_PARAMETER(NumberOfVideoPresentSources);
	UNREFERENCED_PARAMETER(NumberOfChildren);

	return STATUS_SUCCESS;
}

NTSTATUS extension_StopDevice(IN PVOID MiniportDeviceContext)
{
	DbgPrint("DRIVER: StopDevice called\n");
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	return STATUS_SUCCESS;
}

NTSTATUS extension_RemoveDevice(IN PVOID MiniportDeviceContext)
{
	DbgPrint("DRIVER: RemoveDevice called\n");
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	return STATUS_SUCCESS;
}

NTSTATUS extension_D3DDDIQueryAdapterInfo(VOID *InterfaceContext, CONST DXGKARG_QUERYADAPTERINFO *pDDIQAIData)
{
	DbgPrint("DRIVER: QueryAdapterInfo called\n");
	UNREFERENCED_PARAMETER(InterfaceContext);
	UNREFERENCED_PARAMETER(pDDIQAIData);
	return STATUS_SUCCESS;
}

NTSTATUS extension_QueryChildStatus(IN PVOID MiniportDeviceContext, IN PDXGK_CHILD_STATUS ChildStatus, IN BOOLEAN NonDestructiveOnly)
{
	DbgPrint("DRIVER: QueryChildStatus called\n");
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ChildStatus);
	UNREFERENCED_PARAMETER(NonDestructiveOnly);
	return STATUS_SUCCESS;
}

NTSTATUS extension_QueryChildRelations(IN PVOID pvMiniportDeviceContext, IN OUT PDXGK_CHILD_DESCRIPTOR pChildRelations, IN ULONG ChildRelationsSize)
{
	DbgPrint("DRIVER: QueryChildRelations called\n");
	UNREFERENCED_PARAMETER(pvMiniportDeviceContext);
	UNREFERENCED_PARAMETER(pChildRelations);
	UNREFERENCED_PARAMETER(ChildRelationsSize);
	return STATUS_SUCCESS;
}

NTSTATUS extension_QueryDeviceDescriptor(IN_CONST_PVOID MiniportDeviceContext, IN_ULONG ChildUid, INOUT_PDXGK_DEVICE_DESCRIPTOR DeviceDescriptor)
{
	DbgPrint("DRIVER: QueryDeviceDescriptor called\n");
	UNREFERENCED_PARAMETER(MiniportDeviceContext);
	UNREFERENCED_PARAMETER(ChildUid);
	UNREFERENCED_PARAMETER(DeviceDescriptor);
	return STATUS_SUCCESS;
}

NTSTATUS APIENTRY extension_D3DDDIEnumVidPnCofuncModality(CONST HANDLE  hAdapter, CONST DXGKARG_ENUMVIDPNCOFUNCMODALITY* CONST  pEnumCofuncModalityArg)
{
	DbgPrint("DRIVER: EnumVidPnCofuncModality called\n");
	UNREFERENCED_PARAMETER(hAdapter);
	UNREFERENCED_PARAMETER(pEnumCofuncModalityArg);
	return STATUS_SUCCESS;
}